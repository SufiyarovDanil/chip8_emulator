#ifndef ROM_H
#define ROM_H

#include <stddef.h>
#include "defs.h"


typedef struct rom_s rom_t;

/* ROM constructor. If file path is incorrect, rom will destroy itself and returns nullptr */
rom_t* rom_new(const char* const file_path);

/* ROM destructor */
void rom_kill(rom_t* const self);

size_t rom_get_size(const rom_t* const self);

byte* rom_get_data(const rom_t* const self);

#endif // ROM_H
