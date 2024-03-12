#ifndef DMA_CHANNELS_GBA
#define DMA_CHANNELS_GBA

#include <stdint.h>

struct dma_channels {
    volatile uint32_t DMA0SAD;
    volatile uint32_t DMA0DAD;
    volatile uint16_t DMA0CNT_L;
    volatile uint16_t DMA0CNT_H;

    volatile uint32_t DMA1SAD;
    volatile uint32_t DMA1DAD;
    volatile uint16_t DMA1CNT_L;
    volatile uint16_t DMA1CNT_H;

    volatile uint32_t DMA2SAD;
    volatile uint32_t DMA2DAD;
    volatile uint16_t DMA2CNT_L;
    volatile uint16_t DMA2CNT_H;

    volatile uint32_t DMA3SAD;
    volatile uint32_t DMA3DAD;
    volatile uint16_t DMA3CNT_L;
    volatile uint16_t DMA3CNT_H;
};

#endif