#ifndef SERIAL_1_GBA
#define SERIAL_1_GBA

#include <stdint.h>

struct serial_1 {
    volatile uint32_t SIODATA32;

    volatile uint16_t SIOMULTI0;
    volatile uint16_t SIOMULTI1;
    volatile uint16_t SIOMULTI2;
    volatile uint16_t SIOMULTI3;

    volatile uint16_t SIOCNT;
    volatile uint16_t SIOMLT_SEND;
    volatile uint16_t SIODATA8;
};


#endif