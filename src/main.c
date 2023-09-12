#include <stdio.h>
#include "core/rom.h"


int main() {
	int num = 1;

	while (num == 1) {
		printf("enter 0 for over, 1 for continue: ");
		scanf_s("%d", &num);

		for (int i = 0; i < 200; i++) {
			ROM* rom = rom_new("well");
			rom_kill(rom);
		}
	}
	
	return 0;
}
