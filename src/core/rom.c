#include "rom.h"
#include "defs.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>


struct ROM {
	size_t data_size;
	byte* data;
};


/* returns nullptr if file is not founded */
byte* _get_data_rom_file(char* const file_path) {
	FILE* file = (FILE*)0;
	errno_t error = fopen_s(&file, file_path, "rb");

	if (error) {
		printf("failed to open file: %s", file_path);

		return (byte*)0;
	}

	fseek(file, 0L, SEEK_END);

	size_t file_size = ftell(file);
	byte* data = (byte*)malloc(file_size * sizeof(byte));

	fread(data, file_size, 1, file);
	fclose(file);

	return data;
}


ROM* rom_new(char* const file_path) {
	byte* const data = _get_data_rom_file(file_path);

	if (!data) {
		return (ROM*)0;
	}

	ROM* const rom = (ROM*)malloc(sizeof(ROM));

	rom->data_size = 0;
	rom->data = data;

	return rom;
}


void rom_kill(ROM* const self) {
	if (!self) {
		return;
	}

	free(self->data);
	free(self);
}
