#ifndef _INCLUDE_OSAL_H_
#define _INCLUDE_OSAL_H_
#include "include/types.h"

#define ALIGN(x,n)           ((x+(size_t)(n-1)) & ~(size_t)(n-1))
#define WORD_BYTE(x)         (2 * ((x+15) / 16))

typedef void* osal_mutex;
typedef void* osal_spinlock;
typedef void* osal_waitevent;

/* assert */
void osal_assert(int expression);

/* register */
uint32_t osal_read_reg(uint32_t addr);
void osal_write_reg(uint32_t addr, uint32_t value);
void osal_write_mask(uint32_t addr, uint32_t mask);

/* address */
void *osal_remap(uint32_t addr, uint32_t size);
void osal_unmap(void *addr);

/* mutex */
void osal_mutex_init(osal_mutex *lock);
void osal_mutex_deinit(osal_mutex *lock);
void osal_mutex_lock(osal_mutex *lock);
void osal_mutex_unlock(osal_mutex *lock);

/* spin_lock */
void osal_spinlock_init(osal_spinlock *lock, uint8_t mask);
void osal_spinlock_deinit(osal_spinlock *lock);
void osal_spin_lock(osal_spinlock *lock);
void osal_spin_unlock(osal_spinlock *lock);

/* physical memory */
uint32_t osal_palloc(uint32_t size);
void osal_pfree(uint32_t mem);

/* heap memory */
void *osal_malloc(uint32_t size);
void *osal_calloc(uint32_t num, uint32_t size);
void *osal_zalloc(uint32_t size);
void osal_free(void *mem);

void *osal_memcpy(void *dst, const void *src, size_t num);
void *osal_memset(void *dst, int value, size_t num);
int osal_memcmp(void *s1, void *s2, size_t n);

/* interrupt */
void osal_int_set_isr(uint32_t irq_num, void (*isr)(void));
void osal_int_clear(uint32_t mask);
void osal_int_enable(uint32_t mask);
void osal_int_disable(uint32_t mask);
void osal_int_set(uint32_t mask);
uint32_t osal_enter_critical_section(void);
void osal_leave_critical_section(uint32_t);

/* workqueue */
void osal_queue_delayed_work(void *work, int size, void (*work_func)(void *work));

/* sleep */
void osal_sleep();

/* synchronous  */
void osal_wake_up_interruptable(osal_waitevent *e);
void osal_wait_event_interruptable_timeout(osal_waitevent *e, int condition, int timeout_sec);
void osal_wait_event_init(osal_waitevent *e);
void osal_wait_event_deinit(osal_waitevent *e);

/* timer */
void osal_set_timer(void (*timer_func)(void), uint32_t msec);

void osal_init(void);
void osal_cleanup(void);

#endif  //_INCLUDE_OSAL_H_
