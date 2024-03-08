#ifndef SERIAL_2_GBA
#define SERIAL_2_GBA

#include <stdint.h>

struct serial_2 {
    volatile uint16_t RCNT;
    volatile uint16_t IR;

    volatile uint16_t;

    volatile uint16_t JOYCNT;

    volatile uint16_t;

    volatile uint32_t JOY_RECV;
    volatile uint32_t JOY_TRANS;
    volatile uint16_t JOYSTAT;

    volatile uint16_t ;

};


#endif