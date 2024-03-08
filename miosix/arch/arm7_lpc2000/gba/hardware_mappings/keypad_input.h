#ifndef KEYPAD_INPUT_GBA
#define KEYPAD_INPUT_GBA

#include <stdint.h>

struct keypad_input {
    volatile uint16_t KEYINPUT;
    volatile uint16_t KEYCNT;
};

#endif