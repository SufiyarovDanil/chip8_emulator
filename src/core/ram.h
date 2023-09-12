#ifndef RAM_H
#define RAM_H
#include "defs.h"

typedef struct RAM RAM;

/* RAM constructor */
RAM* ram_new();

/* RAM destructor */
void ram_kill(RAM* const self);

byte ram_read(RAM* const self, const word addr);

void ram_write(RAM* const self, const word addr, const byte value);

#endif
