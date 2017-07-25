#ifndef _INCLUDE_LIST_H_
#define _INCLUDE_LIST_H_
#include "types.h"
#include "common/osal.h"

struct list_head {
  struct list_head *next, *prev;
};

static INLINE void INIT_LIST_HEAD(struct list_head *list)
{
    list->next = list->prev = list;
}

static INLINE void _list_add(struct list_head *entry,
                struct list_head *prev, struct list_head *next)
{
    next->prev = entry;
    entry->next = next;
    entry->prev = prev;
    prev->next = entry;
}

static INLINE void list_add(struct list_head *entry, struct list_head *head)
{
    _list_add(entry, head, head->next);
}

static INLINE void list_add_tail(struct list_head *entry, struct list_head *head)
{
    _list_add(entry, head->prev, head);
}

static INLINE void _list_del(struct list_head *prev, struct list_head *next)
{
    osal_assert(prev != NULL);
    osal_assert(next != NULL);

    next->prev = prev;
    prev->next = next;
}

static INLINE void list_del(struct list_head *entry)
{
    _list_del(entry->prev, entry->next);
}

static INLINE int list_empty(struct list_head *head)
{
    return head->next == head;
}

#define container_of(ptr, type, member) \
    (type *)((char *)(ptr) - (char *) &((type *)0)->member)

#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

#define list_first_entry(ptr, type, member) \
    list_entry((ptr)->next, type, member)

#define list_last_entry(ptr, type, member) \
    list_entry((ptr)->prev, type, member)


#define list_next_entry(pos, type, member) \
      list_entry((pos)->member.next, type, member)

#define list_for_each_entry_safe(pos, type, n, head, member)      \
  for (pos = list_first_entry(head, type, member),   \
      n = list_next_entry(pos, type, member);       \
    &pos->member != (head);        \
    pos = n, n = list_next_entry(n, type, member))

#endif
