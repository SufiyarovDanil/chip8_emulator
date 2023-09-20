#ifndef EMULATOR_H
#define EMULATOR_H

#include "core/ram.h"
#include "graphics/display.h"
#include "input/keypad.h"


typedef struct emulator_s emulator_t;

/* emulator constructor */
emulator_t* emulator_new();

/* emulator destructor */
void emulator_kill(emulator_t* const self);

void emulator_start(emulator_t* const self);

display_t* emulator_get_display(const emulator_t* const self);

ram_t* emulator_get_ram(const emulator_t* const self);

keypad_t* emulator_get_keypad(const emulator_t* const self);

#endif // EMULATOR_H
