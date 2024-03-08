#ifndef TIMER_REGISTERS_GBA
#define TIMER_REGISTERS_GBA

#include <stdint.h>

struct timer_registers {
    volatile uint16_t TM0CNT_L;
    volatile uint16_t TM0CNT_H;

    volatile uint16_t TM1CNT_L;
    volatile uint16_t TM1CNT_H;

    volatile uint16_t TM2CNT_L;
    volatile uint16_t TM2CNT_H;

    volatile uint16_t TM3CNT_L;
    volatile uint16_t TM3CNT_H;

    volatile uint16_t;
};


#endif