#include "emulator.h"
#include "core/cpu.h"
#include "stdlib.h"
#include <memory.h>


struct emulator_s {
	display_t* display;
	cpu_t*     cpu;
	ram_t*     ram;
	keypad_t*  keypad;
};


emulator_t* emulator_new() {
	emulator_t* emulator = (emulator_t*)malloc(sizeof(emulator_t));

	emulator->display = display_new();
	emulator->cpu     = cpu_new(emulator);
	emulator->ram     = ram_new();
	emulator->keypad  = keypad_new();

	return emulator;
}


void emulator_kill(emulator_t* const self) {
	if (!self) {
		return;
	}

	display_kill(self->display);
	cpu_kill(self->cpu);
	ram_kill(self->ram);
	keypad_kill(self->keypad);
	free(self);
}


void emulator_start(emulator_t* const self) {

}


display_t* emulator_get_display(const emulator_t* const self) {
	if (!self) {
		return (display_t*)0;
	}

	return self->display;
}


ram_t* emulator_get_ram(const emulator_t* const self) {
	if (!self) {
		return (ram_t*)0;
	}

	return self->ram;
}


keypad_t* emulator_get_keypad(const emulator_t* const self) {
	if (!self) {
		return (keypad_t*)0;
	}

	return self->keypad;
}
