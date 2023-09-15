#ifndef RAM_H
#define RAM_H

#include "rom.h"
#include "defs.h"

typedef struct ram_s ram_t;

/* RAM constructor */
ram_t* ram_new();

/* RAM destructor */
void ram_kill(ram_t* const self);

byte ram_read(const ram_t* const self, const word addr);

void ram_write(ram_t* const self, const word addr, const byte value);

/* copies data from ROM to RAM */
void ram_load_rom(ram_t* const self, const rom_t* const rom);

#endif
