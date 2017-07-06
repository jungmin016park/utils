#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include "common/osal.h"
#include "common/scheduler.h"
#ifdef __XTENSA__
#include <xtensa/xtruntime.h>
#include <xtensa/config/core.h>
#include <xtensa/tie/xt_interrupt.h>  // XT_WAITI(0)
#endif



/********************************************************************
 prototype
 *********************************************************************/
typedef struct SPIN_LOCK_T {
  volatile uint8_t flag;
  uint8_t mask;
} SPIN_LOCK_T;

typedef struct MUTEX_LOCK_T {
  volatile uint8_t flag;
} MUTEX_LOCK_T;

typedef struct OSAL_DB_T {
  uint32_t malloc_size;
} OSAL_DB_T;

OSAL_DB_T osal_db;

/********************************************************************
 prototype
 *********************************************************************/
void *osal_malloc(uint32_t size);
void osal_int_disable(uint32_t mask);
void osal_int_enable(uint32_t mask);


/********************************************************************
 function
 *********************************************************************/
void osal_assert(int expression)
{
  if (expression == 0) {
    //printf("a");
  }

  assert(expression);
}

/* register */
uint32_t osal_read_reg(uint32_t addr)
{
	uint32_t value = 0;
#ifdef __XTENSA__
	value = *(volatile uint32_t *) addr;
#endif
	return value;
}
void osal_write_reg(uint32_t addr, uint32_t value)
{
#ifdef __XTENSA__
	volatile uint32_t *_addr = (uint32_t *) addr;
	*_addr = value;
#endif
}

void osal_write_mask(uint32_t addr, uint32_t mask)
{
  uint32_t tmp;
#ifdef __XTENSA__
  tmp = *(volatile uint32_t *)addr;
  tmp |= mask;
  *(volatile uint32_t *)addr = tmp;
#endif
}
/* address */
void *osal_remap(uint32_t addr, uint32_t size)
{
  return NULL;
}
void osal_unmap(void *addr) {
}

/* mutex */
void osal_mutex_init(osal_mutex *lock)
{
  MUTEX_LOCK_T *_lock;

  _lock = osal_zalloc(sizeof(MUTEX_LOCK_T));

  *lock = _lock;
}
void osal_mutex_deinit(osal_mutex *lock)
{
  osal_free(*lock);
}
void osal_mutex_lock(osal_mutex *lock)
{
#if 0
  MUTEX_LOCK_T *_lock = (MUTEX_LOCK_T *)*lock;

  while(_lock->flag == 1) ;

  _lock->flag == 1;
#endif
}
void osal_mutex_unlock(osal_mutex *lock)
{
#if 0
  MUTEX_LOCK_T *_lock = (MUTEX_LOCK_T *)*lock;

  _lock->flag == 0;
#endif
}

/* spinlock */
void osal_spinlock_init(osal_spinlock *lock, uint8_t mask)
{
  SPIN_LOCK_T *_lock;

  _lock = osal_zalloc(sizeof(SPIN_LOCK_T));
  _lock->mask = mask;

  *lock = _lock;
}
void osal_spinlock_deinit(osal_spinlock *lock)
{
  osal_free(*lock);
}
void osal_spin_lock(osal_spinlock *lock)
{
  SPIN_LOCK_T *_lock = (SPIN_LOCK_T *)*lock;

  while(_lock->flag == 1) ;

  osal_int_disable(_lock->mask);
  _lock->flag = 1;
}
void osal_spin_unlock(osal_spinlock *lock)
{
  SPIN_LOCK_T *_lock = (SPIN_LOCK_T *)*lock;

  osal_assert(_lock->flag == 1);

  _lock->flag = 0;
  osal_int_enable(_lock->mask);
}

/* physical memory */
uint32_t osal_palloc(uint32_t size)
{
  return 0;
}

void osal_pfree(uint32_t mem)
{
}

/* heap memory */
#if 1
#define MALLOC(x) malloc(x)
#else
#define MALLOC(x) memalign(4, x)
#endif

void *osal_malloc(uint32_t size)
{
	void *x;

	osal_assert(size > 0);
	x = MALLOC(size);
	osal_assert(x != NULL);
	osal_db.malloc_size += size;
	return x;
}
void *osal_calloc(uint32_t num, uint32_t size)
{
	void *x;

	osal_assert((num * size) > 0);
	x = MALLOC(num * size);
	osal_assert(x != NULL);
	osal_db.malloc_size += (num *size);
	osal_memset(x, 0, num * size);
	return x;
}
void *osal_zalloc(uint32_t size)
{
	void *x;

	osal_assert(size > 0);
	x = MALLOC(size);
	osal_assert(x != NULL);
	osal_db.malloc_size += size;
	osal_memset(x, 0, size);
	return x;
}
void osal_free(void *mem)
{
	osal_assert(mem != NULL);
	free(mem);
}

void *osal_memcpy(void *dst, const void *src, size_t num)
{
	return memcpy(dst, src, num);
}
void *osal_memset(void *dst, int value, size_t num)
{
	return memset(dst, value, num);
}
int osal_memcmp(void *s1, void *s2, size_t n)
{
	return memcmp(s1, s2, n);
}
/*
int osal_sprintf(char *str, const char *fmt, ...)
{
  va_list ap;
  int ret;

  va_start(ap, fmt);
  ret = vsprintf(str, fmt, ap);
  va_end(ap);

  return ret;
}

char *osal_strcpy(char *dst, char *src)
{

  return strcpy(dst, src);
}
*/

/* INT */
void osal_int_set_isr(uint32_t irq_num, void (*isr)(void))
{
#ifdef __XTENSA__
	_xtos_set_interrupt_handler(irq_num, (_xtos_handler) isr);
#endif
}
void osal_int_clear(uint32_t mask)
{
#ifdef __XTENSA__
	xthal_set_intclear(mask);
#endif
}
void osal_int_enable(uint32_t mask)
{
#ifdef __XTENSA__
	_xtos_ints_on(mask);
#endif
}
void osal_int_disable(uint32_t mask)
{
#ifdef __XTENSA__
	_xtos_ints_off(mask);
#endif
}
void osal_int_set(uint32_t mask)
{
#ifdef __XTENSA__
	xthal_set_intset(mask);
#endif
}

uint32_t osal_enter_critical_section(void)
{

  uint32_t rval;

#ifdef __XTENSA__
  rval = XTOS_SET_INTLEVEL(1);
#endif
  return rval;
}
void osal_leave_critical_section(uint32_t val)
{
#ifdef __XTENSA__
  XTOS_RESTORE_INTLEVEL(val);
#endif
}

/* workqueue */
void osal_queue_delayed_work(void *work, int size, void (*work_func)(void *work))
{
  sched_queue_work(work, size, work_func);
}

void osal_sleep() {
#ifdef __XTENSA__
  XT_WAITI(0);
#endif
}

/* synchronous  */
void osal_wake_up_interruptable(osal_waitevent *e)
{
}
void osal_wait_event_interruptable_timeout(osal_waitevent *e, int condition, int timeout_sec)
{
}
void osal_wait_event_init(osal_waitevent *e)
{
}
void osal_wait_event_deinit(osal_waitevent *e)
{
}

/* timer */
void osal_set_timer(void (*timer_func)(void), uint32_t msec)
{
}

void _exception_handler()
{
  osal_assert(0);
}

void osal_init(void)
{
  int exc_num[] = {13, 28, 29, 20};
  int i;
  int j = sizeof(exc_num) / sizeof(exc_num[0]);

  osal_memset(&osal_db, 0, sizeof(osal_db));

#ifdef __XTENSA__
  for (i = 0; i < j ; i++) {
    _xtos_set_exception_handler(exc_num[i], (_xtos_handler)_exception_handler );
  }
#endif
}
void osal_cleanup(void)
{
}

