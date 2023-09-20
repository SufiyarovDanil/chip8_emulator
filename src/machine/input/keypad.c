#include "keypad.h"
#include "../core/defs.h"
#include <stdlib.h>
#include <memory.h>
#include <GLFW/glfw3.h>

#define KEY_COUNT 0x10


const int keys_sequence[KEY_COUNT] = {
	GLFW_KEY_X, GLFW_KEY_1, GLFW_KEY_2, GLFW_KEY_3,
	GLFW_KEY_Q, GLFW_KEY_W, GLFW_KEY_E, GLFW_KEY_A,
	GLFW_KEY_S, GLFW_KEY_D, GLFW_KEY_Z, GLFW_KEY_C,
	GLFW_KEY_4, GLFW_KEY_R, GLFW_KEY_F, GLFW_KEY_V
};


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


void keypad_poll_keys(keypad_t* const self, GLFWwindow* const window) {
	if (!self) {
		return;
	}

	for (int i = 0; i < KEY_COUNT; i++) {
		const int state = glfwGetKey(window, keys_sequence[i]);

		if (state == GLFW_PRESS) {
			self->keys[i] = 1;
		} else {
			self->keys[i] = 0;
		}
	}
}
