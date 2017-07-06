#ifndef _COMMON_QUEUE_BUF_H_
#define _COMMON_QUEUE_BUF_H_

typedef enum {
  QUEUE_BUF_RENDER_OUT = 0,
  QUEUE_BUF_RENDER_CH_0,
  QUEUE_BUF_RENDER_CH_1,
  QUEUE_BUF_DEC,
  QUEUE_BUF_ES,
  QUEUE_BUF_DEC_VP,
  QUEUE_BUF_ES_VP,
  QUEUE_BUF_NUM,
} QUEUE_BUF_ID_T;

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

void *queue_buf_open(QUEUE_BUF_ID_T buf_id, int num, int meta_size, int buf_size);
void queue_buf_close(void *id);

#endif
