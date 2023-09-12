#include "ram.h"
#include <stdlib.h>
#include <memory.h>

#define RAM_SIZE 0x1000


struct RAM {
	byte space[RAM_SIZE];
};


RAM* ram_new() {
	RAM* ram = (RAM*)malloc(sizeof(RAM));

	memset(ram->space, 0, RAM_SIZE);

	return ram;
}


void ram_kill(RAM* const self) {
	if (!self) {
		return;
	}

	free(self);
}


byte ram_read(RAM* const self, const word addr) {
	if (!self || addr >= RAM_SIZE) {
		return 0;
	}

	return self->space[addr];
}


void ram_write(RAM* const self, const word addr, const byte value) {
	if (!self || addr >= RAM_SIZE) {
		return;
	}

	self->space[addr] = value;
}
