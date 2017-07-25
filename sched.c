#include "common/scheduler.h"
#include "common/util.h"
#include "include/list.h"
#include "include/types.h"
#include "common/osal.h"

#define MAX_WORK_SIZE              30
#define MAX_WORK_QUEUE_NUM         10

typedef struct {
  uint32_t rptr;
  uint32_t wptr;

  struct {
    void *work;
    void (*func)(void *work);
  } wq[MAX_WORK_QUEUE_NUM];
} WORK_QUEUE_T;

typedef struct {
  struct list_head list;
  void *thread_id;
  void (*thread_func)(void *thread_id);
} THREAD_LIST_NODE_T;

typedef struct {
  struct list_head thread_list;
  uint8_t thread_num;

  void *thread_bh;
} SCHED_DB_T;

SCHED_DB_T sched_db;

void *_thread_bh_init()
{
  int i;
  WORK_QUEUE_T *thread = osal_zalloc(sizeof(WORK_QUEUE_T));

  for(i = 0; i < MAX_WORK_QUEUE_NUM; i++) {
    thread->wq[i].work = osal_malloc(MAX_WORK_SIZE);
  }

  return thread;
}

void _thread_bh_process(void *thread_id)
{
  WORK_QUEUE_T *thread = (WORK_QUEUE_T *)thread_id;

  if (thread->rptr == thread->wptr)
    return;

  do {
    thread->wq[thread->rptr].func(thread->wq[thread->rptr].work);
    thread->rptr++;
    thread->rptr %= MAX_WORK_QUEUE_NUM;
  } while(thread->rptr != thread->wptr);
}

void sched_queue_work(void *work, int size, void (*func)(void *work))
{
  WORK_QUEUE_T *thread = (WORK_QUEUE_T *)sched_db.thread_bh;
  uint32_t val;

  osal_assert(size <= MAX_WORK_SIZE);

  val = osal_enter_critical_section();

  osal_memcpy(thread->wq[thread->wptr].work, work, size);
  thread->wq[thread->wptr].func = func;
  thread->wptr++;
  thread->wptr %= MAX_WORK_QUEUE_NUM;
  osal_assert(thread->wptr != thread->rptr);

  osal_leave_critical_section(val);
}

void sched_register(void *thread_id, void (*thread_func)(void *thread_id), int priority)
{
  THREAD_LIST_NODE_T *list_node = (THREAD_LIST_NODE_T *)osal_zalloc(sizeof(THREAD_LIST_NODE_T));

  list_node->thread_id = thread_id;
  list_node->thread_func = thread_func;

  //  TODO : priority implementation

  list_add_tail(&list_node->list, &sched_db.thread_list);
  sched_db.thread_num++;
}

void sched_unregister(void *thread_id)
{

  THREAD_LIST_NODE_T *list_node, *tmp;
  bool found = false;

  list_for_each_entry_safe(list_node, THREAD_LIST_NODE_T, tmp,
                                &sched_db.thread_list, list) {
    if(list_node->thread_id == thread_id) {
      list_del(&list_node->list);
      sched_db.thread_num--;
      found = true;
      break;
    }
  }

  if (!found)
    LOG(LOG_ERR, "not exist\n");

  osal_free(list_node);
}

void sched_run(void)
{
  THREAD_LIST_NODE_T *list_node;

  if (list_empty(&sched_db.thread_list))
    return;

  list_node = list_entry(sched_db.thread_list.next, THREAD_LIST_NODE_T, list);
  list_node->thread_func(list_node->thread_id);
  list_del(&list_node->list);
  list_add_tail(&list_node->list, &sched_db.thread_list);
}

void sched_init(void)
{
  osal_memset(&sched_db, 0, sizeof(sched_db));
  INIT_LIST_HEAD(&sched_db.thread_list);

  sched_db.thread_bh = _thread_bh_init();
  sched_register(sched_db.thread_bh, _thread_bh_process, 0);
}

