#include "include/list.h"
#include "common/osal.h"
#include "common/queue_buf.h"

typedef struct {
  struct list_head list;

  QUEUE_BUF_NODE_T node;
} QUEUE_BUF_LIST_NODE_T;

typedef struct {
  QUEUE_BUF_ID_T buf_id;
  struct list_head free_list;
  struct list_head wait_list;
  struct list_head active_list;

  int total_num;
  int free_num;
  int wait_num;
  int active_num;
} QUEUE_BUF_DB_T;

int queue_buf_push_free(void *id, QUEUE_BUF_NODE_T *node)
{
  QUEUE_BUF_DB_T *this = (QUEUE_BUF_DB_T *)id;
  QUEUE_BUF_LIST_NODE_T *list_node = container_of(node, QUEUE_BUF_LIST_NODE_T, node);

  list_add_tail(&list_node->list, &this->free_list);
  this->free_num++;

  return 0;
}

int queue_buf_pop_free(void *id, QUEUE_BUF_NODE_T **node)
{
  QUEUE_BUF_DB_T *this = (QUEUE_BUF_DB_T *)id;
  QUEUE_BUF_LIST_NODE_T *list_node;

  if (this->free_num == 0)
    return -1;

  list_node = list_entry(this->free_list.next, QUEUE_BUF_LIST_NODE_T, list);
  list_del(&list_node->list);
  this->free_num--;

  *node = &list_node->node;
  return 0;
}

int queue_buf_peep_free(void *id, QUEUE_BUF_NODE_T **node)
{
  QUEUE_BUF_DB_T *this = (QUEUE_BUF_DB_T *)id;
  QUEUE_BUF_LIST_NODE_T *list_node;

  if (this->free_num == 0)
    return -1;

  list_node = list_entry(this->free_list.next, QUEUE_BUF_LIST_NODE_T, list);

  *node = &list_node->node;
  return 0;
}

int queue_buf_push_wait(void *id, QUEUE_BUF_NODE_T *node)
{
  QUEUE_BUF_DB_T *this = (QUEUE_BUF_DB_T *)id;
  QUEUE_BUF_LIST_NODE_T *list_node = container_of(node, QUEUE_BUF_LIST_NODE_T, node);

  list_add_tail(&list_node->list, &this->wait_list);
  this->wait_num++;

  return 0;
}

int queue_buf_pop_wait(void *id, QUEUE_BUF_NODE_T **node)
{
  QUEUE_BUF_DB_T *this = (QUEUE_BUF_DB_T *)id;
  QUEUE_BUF_LIST_NODE_T *list_node;

  if (this->wait_num == 0)
    return -1;

  list_node = list_entry(this->wait_list.next, QUEUE_BUF_LIST_NODE_T, list);
  list_del(&list_node->list);
  this->wait_num--;

  *node = &list_node->node;
  return 0;
}

int queue_buf_peep_wait(void *id, QUEUE_BUF_NODE_T **node)
{
  QUEUE_BUF_DB_T *this = (QUEUE_BUF_DB_T *)id;
  QUEUE_BUF_LIST_NODE_T *list_node;

  if (this->wait_num == 0)
    return -1;

  list_node = list_entry(this->wait_list.next, QUEUE_BUF_LIST_NODE_T, list);

  *node = &list_node->node;
  return 0;
}

int queue_buf_push_active(void *id, QUEUE_BUF_NODE_T *node)
{
  QUEUE_BUF_DB_T *this = (QUEUE_BUF_DB_T *)id;
  QUEUE_BUF_LIST_NODE_T *list_node = container_of(node, QUEUE_BUF_LIST_NODE_T, node);

  list_add_tail(&list_node->list, &this->active_list);
  this->active_num++;

  return 0;
}

int queue_buf_pop_active(void *id, QUEUE_BUF_NODE_T **node)
{
  QUEUE_BUF_DB_T *this = (QUEUE_BUF_DB_T *)id;
  QUEUE_BUF_LIST_NODE_T *list_node;

  if (this->active_num == 0)
    return -1;

  list_node = list_entry(this->active_list.next, QUEUE_BUF_LIST_NODE_T, list);
  list_del(&list_node->list);
  this->active_num--;

  *node = &list_node->node;
  return 0;
}

int queue_buf_peep_active(void *id, QUEUE_BUF_NODE_T **node)
{
  QUEUE_BUF_DB_T *this = (QUEUE_BUF_DB_T *)id;
  QUEUE_BUF_LIST_NODE_T *list_node;

  if (this->active_num == 0)
    return -1;

  list_node = list_entry(this->active_list.next, QUEUE_BUF_LIST_NODE_T, list);

  *node = &list_node->node;
  return 0;
}

void *queue_buf_open(QUEUE_BUF_ID_T buf_id, int num, int meta_size, int buf_size)
{
  QUEUE_BUF_DB_T *this = (QUEUE_BUF_DB_T *)osal_zalloc(sizeof(QUEUE_BUF_DB_T));
  int i;

  INIT_LIST_HEAD(&this->free_list);
  INIT_LIST_HEAD(&this->wait_list);
  INIT_LIST_HEAD(&this->active_list);
  this->total_num = num;
  this->buf_id = buf_id;

  for (i = 0; i < num; i++) {
    QUEUE_BUF_LIST_NODE_T *list_node = (QUEUE_BUF_LIST_NODE_T *)osal_zalloc(sizeof(QUEUE_BUF_LIST_NODE_T));
    if (meta_size)
      list_node->node.meta = (uint8_t *)osal_malloc(meta_size);
    if (buf_size)
      list_node->node.buf = (uint8_t *)osal_malloc(buf_size);
    list_add_tail(&list_node->list, &this->free_list);
    this->free_num++;
  }

  return this;
}

void queue_buf_close(void *id)
{
  QUEUE_BUF_DB_T *this = (QUEUE_BUF_DB_T *)id;
  QUEUE_BUF_LIST_NODE_T *list_node, *tmp;

  osal_assert(this->total_num == this->free_num);

  list_for_each_entry_safe(list_node, QUEUE_BUF_LIST_NODE_T, tmp,
                          &this->free_list, list) {
    list_del(&list_node->list);
    if (list_node->node.meta)
      osal_free(list_node->node.meta);
    if (list_node->node.buf)
      osal_free(list_node->node.buf);
    osal_free(list_node);
  }

  osal_free(this);
}

