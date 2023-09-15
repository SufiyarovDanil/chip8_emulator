#include "emulator.h"
#include "core/cpu.h"
#include "core/ram.h"
#include "stdlib.h"
#include <memory.h>


struct emulator_s {
	cpu_t* cpu;
	ram_t* ram;
};


emulator_t* emulator_new() {
	emulator_t* emulator = (emulator_t*)malloc(sizeof(emulator_t));

	emulator->cpu = cpu_new();
	emulator->ram = ram_new();

	return emulator;
}


void emulator_kill(emulator_t* const self) {
	if (!self) {
		return;
	}

	cpu_kill(self->cpu);
	ram_kill(self->ram);
	free(self);
}
