#ifndef INTERRUPTS_REGISTERS_GBA
#define INTERRUPTS_REGISTERS_GBA

#include <stdint.h>

struct interrupts_registers {
    volatile uint16_t IE;
    volatile uint16_t IF;
    volatile uint16_t WAITCNT;

    volatile uint16_t UNUSED_1;

    volatile uint16_t IME;

    volatile uint16_t UNUSED_2;

    volatile uint16_t POSTFLG;
    volatile uint16_t HALTCNT;
};

#endif