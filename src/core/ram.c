#include "ram.h"
#include <stdlib.h>
#include <memory.h>

#define RAM_SIZE 0x1000


struct RAM {
	unsigned char space[RAM_SIZE];
};


RAM* ram_new() {
	RAM* ram = (RAM*)malloc(sizeof(RAM));

	memset(ram->space, 0, RAM_SIZE);

	return ram;
}
