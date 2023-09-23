#include "display.h"
#include <stdlib.h>
#include <memory.h>


struct display_s {
	byte pixels[DISPLAY_SIZE];
};


display_t* display_new() {
	display_t* const display = (display_t*)malloc(sizeof(display_t));

	memset(display->pixels, 0, DISPLAY_SIZE);

	return display;
}


void display_kill(display_t* const self) {
	if (!self) {
		return;
	}

	free(self);
}


void display_clear(display_t* const self) {
	if (!self) {
		return;
	}

	memset(self->pixels, 0, DISPLAY_SIZE);
}


byte display_read_pixel(const display_t* const self, const word addr) {
	if (!self || addr >= DISPLAY_SIZE) {
		return 0;
	}

	return self->pixels[addr];
}


void display_write_pixel(display_t* const self, const word addr, const byte value) {
	if (!self || addr >= DISPLAY_SIZE) {
		return;
	}

	self->pixels[addr] = value;
}


word display_get_size(const display_t* const self) {
	if (!self) {
		return 0;
	}

	return DISPLAY_SIZE;
}


size_t display_count_set_pixels(const display_t* const self) {
	if (!self) {
		return 0;
	}

	word result = 0;

	for (word i = 0; i < DISPLAY_SIZE; i++) {
		result += self->pixels[i];
	}

	return result;
}
