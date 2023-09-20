#ifndef KEYPAD_H
#define KEYPAD_H

#include "../core/defs.h"

typedef struct keypad_s keypad_t;

typedef struct GLFWwindow GLFWwindow;

/* keypad constructor */
keypad_t* keypad_new();

/* keypad destructor */
void keypad_kill(keypad_t* const self);

byte keypad_key_at(const keypad_t* const self, word key_index);

byte keypad_any_key_pressed(const keypad_t* const self);

void keypad_poll_keys(keypad_t* const self, GLFWwindow* const window);

#endif // KEYPAD_H
