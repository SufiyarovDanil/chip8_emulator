#include "cpu.h"
#include "ram.h"
#include "instruction.h"
#include <stdlib.h>
#include <memory.h>


struct CPU {
	byte v[CPU_DATA_REGISTERS_COUNT];	// data registers V0-VF
	word i;								// index register
	word pc;							// program counter
	word stack[CPU_STACK_SIZE];			// subroutine stack
	byte stack_ptr;						// subroutine stack pointer
};


CPU* cpu_new() {
	CPU* cpu = (CPU*)malloc(sizeof(CPU));

	memset(cpu->v, 0, CPU_DATA_REGISTERS_COUNT * sizeof(byte));
	cpu->i = 0;
	cpu->pc = CPU_ENTRY_POINT;
	memset(cpu->stack, 0, CPU_STACK_SIZE * sizeof(word));
	cpu->stack_ptr = 0;

	return cpu;
}


void cpu_kill(CPU* const self) {
	if (!self) {
		return;
	}

	free(self);
}


void cpu_exec_instruction(CPU* const self, RAM* const ram) {
	if (!self) {
		return;
	}

	const byte left_byte  = ram_read(ram, self->pc);
	const byte right_byte = ram_read(ram, self->pc + 1);

	Instruction* instruction = instruction_new(left_byte, right_byte);

	self->pc += 2;

	// TODO

	instruction_kill(instruction);
}
