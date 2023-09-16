//#include <stdio.h>
#include "machine/emulator.h"


int main() {
	emulator_t* emulator = emulator_new();

	emulator_start(emulator);
	emulator_kill(emulator);

	return 0;
}
