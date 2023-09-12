#ifndef RAM_H
#define RAM_H
#include "defs.h"

typedef struct RAM RAM;

typedef struct ROM ROM;

/* RAM constructor */
RAM* ram_new();

/* RAM destructor */
void ram_kill(RAM* const self);

byte ram_read(const RAM* const self, const word addr);

void ram_write(RAM* const self, const word addr, const byte value);

/* copies data from ROM to RAM */
void ram_load_rom(RAM* const self, const ROM* const rom);

#endif
