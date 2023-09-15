#include "display.h"
#include <memory>

#define DISPLAY_WIDTH 64
#define DISPLAY_HEIGHT 32


struct display_s {
	byte pixels[DISPLAY_WIDTH * DISPLAY_HEIGHT];
};


display_t* display_new() {
	display_t* const display = (display_t*)malloc(sizeof(display_t));

	memset(display->pixels, 0, DISPLAY_WIDTH * DISPLAY_HEIGHT);

	return display;
}


void display_kill(display_t* const self) {
	if (!self) {
		return;
	}

	free(self);
}
