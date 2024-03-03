#ifndef __MALLOC_H__
#define __MALLOC_H__

#include "main.h"
#include "stdint.h"

/* 内部SRAM */
#define BlOCK_SIZE 32                   /* 内存块大小，必须为2的幂次方 */
#define MAX_SIZE 40 * 1024              /* 最大内存 */
#define BLOCK_NUM MAX_SIZE / BlOCK_SIZE /* 内存块个数 */

void mallocInit(void);
void *mymalloc(uint16_t size);
void myfree(void *ptr);
uint16_t getMemoryUsage(void);

#endif /*__MALLOC_H__*/
