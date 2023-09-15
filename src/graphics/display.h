#ifndef DISPLAY_H
#define DISPLAY_H

#include "../core/defs.h"

typedef struct display_s display_t;

/* display constructor */
display_t* display_new();

/* display destructor */
void display_kill(display_t* const self);

byte display_read_pixel(const display_t* const self, const word addr);

void display_write_pixel(display_t* const self, const word addr, const byte value);

word display_get_size(const display_t* const self);

#endif // DISPLAY_H
