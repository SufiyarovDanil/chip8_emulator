#include <stdio.h>
#include "core/rom.h"


int main() {
	int num = 1;

	while (num == 1) {
		printf("enter 0 for over, 1 for continue: ");
		scanf_s("%d", &num);

		ROM* rom = rom_new("D:/Projects/emus/chip8_emulator/res/chip8-roms-master/programs/IBM Logo.ch8");
		printf("%zu\n", rom_get_size(rom));
		rom_kill(rom);

		rom = rom_new("D:/Projects/emus/chip8_emulator/res/chip8-roms-master/programs/Chip8 Picture.ch8");
		printf("%zu\n", rom_get_size(rom));
		rom_kill(rom);
	}

	return 0;
}
