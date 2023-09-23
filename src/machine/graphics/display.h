#ifndef DISPLAY_H
#define DISPLAY_H

#include "../core/defs.h"

#define DISPLAY_WIDTH 64
#define DISPLAY_HEIGHT 32
#define DISPLAY_SIZE DISPLAY_WIDTH * DISPLAY_HEIGHT


typedef struct display_s display_t;

/* display constructor */
display_t* display_new();

/* display destructor */
void display_kill(display_t* const self);

void display_clear(display_t* const self);

byte display_read_pixel(const display_t* const self, const word addr);

void display_write_pixel(display_t* const self, const word addr, const byte value);

word display_get_size(const display_t* const self);

size_t display_count_set_pixels(const display_t* const self);

#endif // DISPLAY_H
