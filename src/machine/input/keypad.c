#include "keypad.h"
#include "../core/defs.h"
#include <stdlib.h>
#include <memory.h>

#define KEY_COUNT 0xF


struct keypad_s {
	byte keys[KEY_COUNT];
};


keypad_t* keypad_new() {
	keypad_t* const keypad = (keypad_t*)malloc(sizeof(keypad_t));

	memset(keypad->keys, 0, KEY_COUNT);

	return keypad;
}


void keypad_kill(keypad_t* const self) {
	if (!self) {
		return;
	}

	free(self);
}
