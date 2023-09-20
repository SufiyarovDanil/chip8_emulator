#ifndef KEYPAD_H
#define KEYPAD_H

typedef struct keypad_s keypad_t;

typedef struct GLFWwindow GLFWwindow;

/* keypad constructor */
keypad_t* keypad_new();

/* keypad destructor */
void keypad_kill(keypad_t* const self);

void keypad_poll_keys(keypad_t* const self, GLFWwindow* const window);

#endif // KEYPAD_H
