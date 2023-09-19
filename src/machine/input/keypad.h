#ifndef KEYPAD_H
#define KEYPAD_H

typedef struct keypad_s keypad_t;

/* keypad constructor */
keypad_t* keypad_new();

/* keypad destructor */
void keypad_kill(keypad_t* const self);

#endif // KEYPAD_H
