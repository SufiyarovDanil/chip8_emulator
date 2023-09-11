#include <stdio.h>
#include "core/cpu.h"


int main() {
	CPU* cpu = cpu_new();

	printf("%d\n", cpu_get_i(cpu));
	cpu_set_i(cpu, 20);
	printf("%d\n", cpu_get_i(cpu));

	cpu_kill(cpu);
	
	return 0;
}
