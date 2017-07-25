#ifndef _INCLUDE_SCHEDULER_H_
#define _INCLUDE_SCHEDULER_H_
#include "include/types.h"

void sched_queue_work(void *work, int size, void (*func)(void *work));
void sched_register(void *thread_id, void (*thread_func)(void *thread_id), int priority);
void sched_unregister(void *thread_id);
void sched_run(void);
void sched_init(void);
#endif
