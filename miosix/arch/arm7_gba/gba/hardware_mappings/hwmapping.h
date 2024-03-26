#ifndef HWMAPPING_H
#define HWMAPPING_H

#include "lcd_registers.h"
#include "sound_registers.h"
#include "dma_channels.h"
#include "timer_registers.h"
#include "serial_1.h"
#include "keypad_input.h"
#include "serial_2.h"
#include "interrupts_registers.h"
#include "gpio_registers.h"

#define LCD_REGISTERS ((struct lcd_registers *) 0x4000000)
#define SOUND_REGISTERS ((struct sound_registers *) 0x4000060)
#define DMA_CHANNELS ((struct dma_channels *) 0x40000B0)
#define TIMER_REGISTERS ((struct timer_registers *) 0x4000100)
#define SERIAL_1 ((struct serial_1 *) 0x4000120)
#define KEYPAD_INPUT ((struct keypad_input *) 0x4000130)
#define SERIAL_2 ((struct serial_2 *) 0x4000134)
#define INTERRUPT_REGISTERS ((struct interrupt_registers *) 0x4000200)

/* The screen is simply a pointer into memory at a specific address this
 * pointer points to 16-bit colors of which there are 240x160 */
#define LCD_DISPLAY ((volatile uint16_t *) 0x6000000)

#define GPIO_BASE 0x80000C4)

#endif