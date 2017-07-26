#include "include/cma.h"
#include "include/list.h"
#include "include/log.h"


typedef struct segment_t {
  struct _list_head list;
  uint32 addr;
  uint32 size;
} segment_t;

struct {
  struct _list_head segment_list;
  OsalMutex lock;

  uint32 heap_base;
  uint32 heap_size;
} cma_db;

void _PrintAllSegments(void) {
  segment_t *list_node, *tmp;

   _list_for_each_entry_safe(list_node, segment_t, tmp,
                              &cma_db.segment_list, list) {
     log(LOG_MEM, "segment 0x%08x~0x%08x(0x%x)\n", list_node->addr
       , list_node->addr + list_node->size - 1, list_node->size);
   }
}

int _findPosition(segment_t *seg, uint32 size) {
  segment_t *list_node = NULL, *tmp, *list_node_next;
  uint32 candidate_start;
  uint32 candidate_end;
  uint8 first_flag = 0;

  /* first segment */
  if (_list_empty(&cma_db.segment_list)) {
    candidate_start = cma_db.heap_base;
    candidate_end = candidate_start + size -1;
    if (candidate_end > (cma_db.heap_base + cma_db.heap_size - 1))
      return -1;
    else
      first_flag = 1;
  } else {
    _list_for_each_entry_safe(list_node, segment_t, tmp,
                              &cma_db.segment_list, list) {
      /* candidate */
      candidate_start = list_node->addr + list_node->size;
      candidate_end = candidate_start + size -1;

      /* last segment */
      if (list_node->list.next == &cma_db.segment_list) {
        if (candidate_end <= (cma_db.heap_base + cma_db.heap_size -1))
          break;
        else {
          log(LOG_ERROR, "memory heap is full\n");
          return -1;
        }
      }

      /* compare next segment */
      list_node_next = _list_next_entry(list_node, segment_t, list);
      if (candidate_end < list_node_next->addr)
        break;
    }
  }

  seg->addr = candidate_start;
  seg->size = size;
  if (first_flag)
    _list_add(&seg->list, &cma_db.segment_list);
  else
    _list_add(&seg->list, &list_node->list);
  return 0;
}

uint32 CmaAlloc(uint32 size) {
  segment_t *seg;

  seg = (segment_t *)OsalZalloc(sizeof(segment_t));

  /* find available range */
  if (_findPosition(seg, size) < 0) {
    OsalFree(seg);
    return 0;
  }

  return seg->addr;
}

void CmaFree(uint32 addr) {
  segment_t *list_node, *tmp;
  int found = 0;

  _list_for_each_entry_safe(list_node, segment_t, tmp,
                              &cma_db.segment_list, list) {
    if (list_node->addr == addr) {
      found = 1;
      break;
    }
  }

  OsalAssert(found);

  _list_del(&list_node->list);
  OsalFree(list_node);
}

void CmaInit(uint32 heap_base, uint32 heap_size) {
  cma_db.heap_base = heap_base;
  cma_db.heap_size = heap_size;

  _INIT_LIST_HEAD(&cma_db.segment_list);
}

