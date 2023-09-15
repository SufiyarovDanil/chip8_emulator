//#include <stdio.h>
#include "machine/emulator.h"


int main() {
	while (1) {
		emulator_t* emulator = emulator_new();
		emulator_kill(emulator);
	}

	return 0;
}
