#include <stdio.h>
#include "core/cpu.h"
#include "core/ram.h"
#include "core/rom.h"


int main() {
	while (1) { // memory leak checking
		CPU* cpu = cpu_new();
		RAM* ram = ram_new();

		{
			ROM* rom = rom_new("D:/Projects/emus/chip8_emulator/res/chip8-roms-master/programs/IBM Logo.ch8");

			ram_load_rom(ram, rom);
			rom_kill(rom);
		}

		for (int i = 0; i < 100; i++) {
			cpu_exec_instruction(cpu, ram);
		}

		ram_kill(ram);
		cpu_kill(cpu);
	}

	return 0;
}
