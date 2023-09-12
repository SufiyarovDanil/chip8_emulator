#include <stdio.h>
#include "core/rom.h"


int main() {
	int num = 1;

	while (num == 1) {
		int num;

		printf("enter 0 for over, 1 for continue: ");
		scanf_s("%d", &num);

		ROM* rom = rom_new("ergsegrser");
		
		rom_get_size(rom);

		rom_kill(rom);
	}
	
	return 0;
}
