#ifndef ROM_H
#define ROM_H

#include <stddef.h>
#include "defs.h"


typedef struct ROM ROM;

/* ROM constructor. If file path is incorrect, rom will destroy itself and returns nullptr */
ROM* rom_new(const char* const file_path);

/* ROM destructor */
void rom_kill(ROM* const self);

size_t rom_get_size(const ROM* const self);

byte* rom_get_data(const ROM* const self);

#endif // ROM_H
