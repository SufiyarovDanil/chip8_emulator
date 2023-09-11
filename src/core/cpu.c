#include "cpu.h"
#include "instruction.h"
#include <stdlib.h>
#include <memory.h>

#define DATA_REGISTERS_COUNT 0x10
#define STACK_SIZE 0xC
#define ENTRY_POINT 0x200


struct CPU {
	byte v[DATA_REGISTERS_COUNT];	// data registers V0-VF
	word i;							// index register
	word pc;						// program counter
	word stack[STACK_SIZE];			// subroutine stack
	byte stack_ptr;					// subroutine stack pointer
};


CPU* cpu_new() {
	CPU* cpu = (CPU*)malloc(sizeof(CPU));

	memset(cpu->v, 0, DATA_REGISTERS_COUNT * sizeof(byte));
	cpu->i = 0;
	cpu->pc = ENTRY_POINT;
	memset(cpu->stack, 0, STACK_SIZE * sizeof(word));
	cpu->stack_ptr = 0;

	return cpu;
}


void cpu_kill(CPU* const self) {
	if (!self) {
		return;
	}

	free(self);
}


void cpu_set_i(CPU* const self, const byte i) {
	if (!self) {
		return;
	}

	self->i = i;
}


byte cpu_get_i(CPU* const self) {
	if (!self) {
		return 0;
	}

	return self->i;
}


void cpu_exec_instruction(CPU* const self, const word opcode) {
	if (!self) {
		return;
	}

	// TODO
}
