#include "ram.h"
#include "rom.h"
#include "cpu.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define FONT_SIZE 0x50
#define RAM_SIZE  0x1000


const byte font_set[FONT_SIZE] = {
	0xF0, 0x90, 0x90, 0x90, 0xF0,	// 0
	0x20, 0x60, 0x20, 0x20, 0x70,	// 1
	0xF0, 0x10, 0xF0, 0x80, 0xF0,	// 2
	0xF0, 0x10, 0xF0, 0x10, 0xF0,	// 3
	0x90, 0x90, 0xF0, 0x10, 0x10,	// 4
	0xF0, 0x80, 0xF0, 0x10, 0xF0,	// 5
	0xF0, 0x80, 0xF0, 0x90, 0xF0,	// 6
	0xF0, 0x10, 0x20, 0x40, 0x40,	// 7
	0xF0, 0x90, 0xF0, 0x90, 0xF0,	// 8
	0xF0, 0x90, 0xF0, 0x10, 0xF0,	// 9
	0xF0, 0x90, 0xF0, 0x90, 0x90,	// A
	0xE0, 0x90, 0xE0, 0x90, 0xE0,	// B
	0xF0, 0x80, 0x80, 0x80, 0xF0,	// C
	0xE0, 0x90, 0x90, 0x90, 0xE0,	// D
	0xF0, 0x80, 0xF0, 0x80, 0xF0,	// E
	0xF0, 0x80, 0xF0, 0x80, 0x80	// F
};


struct RAM {
	byte space[RAM_SIZE];
};


void _ram_load_font(RAM* const self) {
	if (!self) {
		return;
	}

	memcpy(self->space, font_set, FONT_SIZE);
}


RAM* ram_new() {
	RAM* ram = (RAM*)malloc(sizeof(RAM));

	memset(ram->space, 0, RAM_SIZE);
	_ram_load_font(ram);

	return ram;
}


void ram_kill(RAM* const self) {
	if (!self) {
		return;
	}

	free(self);
}


byte ram_read(const RAM* const self, const word addr) {
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


void ram_load_rom(RAM* const self, const ROM* const rom) {
	if (!self || !rom) {
		return;
	}

	if (rom_get_size(rom) > RAM_SIZE - CPU_ENTRY_POINT) {
		printf("ROM size is bigger than RAM\n");

		return;
	}

	memcpy(self->space + CPU_ENTRY_POINT, rom_get_data(rom), rom_get_size(rom));
}
