#ifndef LCD_REGISTERS_GBA
#define LCD_REGISTERS_GBA

#include <stdint.h>

struct lcd_registers {
    volatile uint16_t DISPCNT;
    volatile uint16_t GREEN_SWAP;
    volatile uint16_t DISPSTAT;
    volatile uint16_t VCOUNT;

    volatile uint16_t BG0CNT;
    volatile uint16_t BG1CNT;
    volatile uint16_t BG2CNT;
    volatile uint16_t BG3CNT;

    volatile uint16_t BG0HOFS;
    volatile uint16_t BG0VOFS;
    volatile uint16_t BG1HOFS;
    volatile uint16_t BG1V0FS;
    volatile uint16_t BG2HOFS;
    volatile uint16_t BG2V0FS;
    volatile uint16_t BG3HOFS;
    volatile uint16_t BG3VOFS;

    volatile uint16_t BG2PA;
    volatile uint16_t BG2PB;
    volatile uint16_t BG2PC;
    volatile uint16_t BG2PD;

    volatile uint32_t BG2X;
    volatile uint32_t BG2Y;

    volatile uint16_t BG3PA;
    volatile uint16_t BG3PB;
    volatile uint16_t BG3PC;
    volatile uint16_t BG3PD;

    volatile uint32_t BG3X;
    volatile uint32_t BG3Y;

    volatile uint16_t WIN0H;
    volatile uint16_t WIN1H;
    volatile uint16_t WIN0V;
    volatile uint16_t WIN1V;
    volatile uint16_t WININ;
    volatile uint16_t WINOUT;

    volatile uint16_t MOSAIC;

    volatile uint16_t UNUSED;

    volatile uint16_t BLDCNT;
    volatile uint16_t BLDALPHA;
    volatile uint16_t BLDY;
};

#endif