#ifndef SOUND_REGISTERS_GBA
#define SOUND_REGISTERS_GBA

#include <stdint.h>

struct sound_registers {
    volatile uint16_t SOUND1CNT_L;
    volatile uint16_t SOUND1CNT_H;
    volatile uint16_t SOUND1CNT_X;

    volatile uint16_t UNUSED_1;

    volatile uint16_t SOUND2CNT_L;

    volatile uint16_t UNUSED_2;

    volatile uint16_t SOUND2CNT_H;

    volatile uint16_t UNUSED_3;

    volatile uint16_t SOUND3CNT_L;
    volatile uint16_t SOUND3CNT_H;
    volatile uint16_t SOUND3CNT_X;

    volatile uint16_t UNUSED_4;

    volatile uint16_t SOUND4CNT_L;

    volatile uint16_t UNUSED_5;

    volatile uint16_t SOUND4CNT_H;

    volatile uint16_t UNUSED_6;

    volatile uint16_t SOUNDCNT_L;
    volatile uint16_t SOUNDCNT_H;
    volatile uint16_t SOUNDCNT_X;

    volatile uint16_t UNUSED_7;

    volatile uint16_t SOUNDBIAS;

    volatile uint16_t UNUSED_8;
    
    volatile uint16_t WAVE_RAM[16];
    volatile uint32_t FIFO_A;
    volatile uint32_t FIFO_B;
};


#endif