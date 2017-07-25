#ifndef _COMMON_QUEUE_BUF_H_
#define _COMMON_QUEUE_BUF_H_

typedef struct {
  uint8_t *meta;
  uint8_t *buf;
} QUEUE_BUF_NODE_T;

int queue_buf_push_free(void *id, QUEUE_BUF_NODE_T *node);
int queue_buf_pop_free(void *id, QUEUE_BUF_NODE_T **node);
int queue_buf_peep_free(void *id, QUEUE_BUF_NODE_T **node);

int queue_buf_push_wait(void *id, QUEUE_BUF_NODE_T *node);
int queue_buf_pop_wait(void *id, QUEUE_BUF_NODE_T **node);
int queue_buf_peep_wait(void *id, QUEUE_BUF_NODE_T **node);

int queue_buf_push_active(void *id, QUEUE_BUF_NODE_T *node);
int queue_buf_pop_active(void *id, QUEUE_BUF_NODE_T **node);
int queue_buf_peep_active(void *id, QUEUE_BUF_NODE_T **node);

void *queue_buf_open(int num, int meta_size, int buf_size);
void queue_buf_close(void *id);

#endif
