#include "malloc.h"

static __align(64) uint8_t pool[MAX_SIZE]; /* 内存池 */
static uint16_t map[BLOCK_NUM];            /* 内存管理表 */

/**
 * @brief 将指定的字符c复制len次到ptr指向的内存中
 *
 * @param ptr 指向要填充的内存的指针
 * @param c 要复制的字符
 * @param len 要复制的次数
 */
void mymemset(void *ptr, int c, int len)
{
    uint8_t *p = ptr;

    while (len--)
        *p++ = c; /* 将字符c复制到指针p指向的内存位置 */
}

/**
 * @brief 初始化内存分配器
 */
void mallocInit(void)
{
    mymemset(map, 0, BLOCK_NUM * sizeof(uint16_t));
}

/**
 * @brief 分配一块指定大小的内存空间
 * @param size 内存空间的大小
 * @return void* 分配的内存空间的指针，如果分配失败则返回NULL
 */
void *mymalloc(uint16_t size)
{
    long offset = 0;                         /* 记录待分配的内存块的偏移量 */
    uint32_t freeBlocks = 0;                 /* 记录可用的连续内存块的数量 */
    uint32_t needblocks = size / BlOCK_SIZE; /* 计算需要的连续内存块的数量 */

    if (size == 0)   /* 如果需要的连续内存块的数量为0，不需要进行分配 */
        return NULL; /* 返回NULL */

    if (size % BlOCK_SIZE) /* 如果需要的内存块大小不是BlOCK_SIZE的整数倍 */
        needblocks++;      /* 需要的连续内存块的数量加1 */

    for (offset = BLOCK_NUM - 1; offset >= 0; offset--) /* 从内存块的最后一个位置开始遍历 */
    {
        if (map[offset] != 0) /* 如果当前内存块已经被占用 */
        {
            freeBlocks = 0; /* 重置可用的连续内存块的数量 */
            continue;
        }

        freeBlocks++;                 /* 可用的连续内存块的数量加1 */
        if (freeBlocks == needblocks) /* 如果可用的连续内存块的数量等于需要的连续内存块的数量 */
        {
            for (uint32_t i = 0; i < needblocks; i++) /* 将当前连续内存块标记为已占用 */
            {
                map[offset + i] = needblocks;
            }
            return (void *)((uint32_t)pool + offset * BlOCK_SIZE); /* 返回分配的内存空间的指针 */
        }
    }
    return NULL;
}

/**
 * @brief 释放内存块
 * @param ptr 要释放的内存块指针
 * @return 无
 */
void myfree(void *ptr)
{
    uint32_t offset = (uint32_t)ptr - (uint32_t)pool; /* 计算内存块在内存池中的偏移量 */
    if (ptr == NULL)                                  /* 如果指针为空，则直接返回 */
        return;
    if (offset >= MAX_SIZE) /* 如果偏移量超出内存块数量，则直接返回 */
        return;
    int tmp = offset / BlOCK_SIZE;
    int maxTmp = map[tmp];
    for (int i = 0; i < maxTmp; i++) /* 遍历内存块中的所有元素 */
    {
        map[tmp + i] = 0; /* 设置为未占用状态 */
    }
}

/**
 * @brief 获取内存使用率
 *
 * @return uint16_t 内存使用率，范围[0,100] %
 */
uint16_t getMemoryUsage(void)
{
    uint32_t usedBlocks = 0; /* 记录已使用的连续内存块的数量 */

    for (uint32_t i = 0; i < BLOCK_NUM; i++) /* 遍历内存管理 */
    {
        if (map[i] != 0)  /* 如果当前内存块已经被占用 */
            usedBlocks++; /* 已使用的连续内存块的数量加1 */
    }
    return (usedBlocks * 100) / (BLOCK_NUM); /* 内存使用率 */
}
