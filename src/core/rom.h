#ifndef ROM_H
#define ROM_H

typedef struct ROM ROM;

/* ROM constructor. If file path is incorrect, rom will destroy itself and returns nullptr */
ROM* rom_new(char* const file_path);

/* ROM destructor */
void rom_kill(ROM* const self);

#endif // ROM_H
