#ifndef GPIO_REGISTERS_GBA
#define GPIO_REGISTERS_GBA

#include <stdint.h>

struct gpio_registers {
    volatile uint16_t DATA;
    volatile uint16_t DIR;
    volatile uint16_t CTRL;
};

#endif