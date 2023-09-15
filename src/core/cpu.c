#include "cpu.h"
#include "ram.h"
#include "instruction.h"
#include <stdlib.h>
#include <memory.h>


void _cpu_0x0(CPU* const self, const Instruction* const instruction);
void _cpu_0x1(CPU* const self, const Instruction* const instruction);
void _cpu_0x2(CPU* const self, const Instruction* const instruction);
void _cpu_0x3(CPU* const self, const Instruction* const instruction);
void _cpu_0x4(CPU* const self, const Instruction* const instruction);
void _cpu_0x5(CPU* const self, const Instruction* const instruction);
void _cpu_0x6(CPU* const self, const Instruction* const instruction);
void _cpu_0x7(CPU* const self, const Instruction* const instruction);
void _cpu_0x8(CPU* const self, const Instruction* const instruction);
void _cpu_0x9(CPU* const self, const Instruction* const instruction);
void _cpu_0xA(CPU* const self, const Instruction* const instruction);
void _cpu_0xB(CPU* const self, const Instruction* const instruction);
void _cpu_0xC(CPU* const self, const Instruction* const instruction);
void _cpu_0xD(CPU* const self, const Instruction* const instruction);
void _cpu_0xE(CPU* const self, const Instruction* const instruction);
void _cpu_0xF(CPU* const self, const Instruction* const instruction);


void (* const instruction_set[])(CPU* const, const Instruction* const) = {
	_cpu_0x0, _cpu_0x1, _cpu_0x2, _cpu_0x3,
	_cpu_0x4, _cpu_0x5, _cpu_0x6, _cpu_0x7,
	_cpu_0x8, _cpu_0x9, _cpu_0xA, _cpu_0xB,
	_cpu_0xC, _cpu_0xD, _cpu_0xE, _cpu_0xF
};


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
	const word category = (instruction_get_opcode(instruction) >> 12) & 0xF;

	self->pc += 2;

	instruction_set[category](self, instruction);
	instruction_kill(instruction);
}


void _cpu_0x0(CPU* const self, const Instruction* const instruction) {
	if (!self || !instruction) {
		return;
	}

	const word nnn = instruction_get_nnn(instruction);

	switch (nnn)
	{
	case 0xE0:
		// TODO clear display
		break;
	case 0xEE:
		self->stack_ptr -= 1;
		self->pc = self->stack[self->stack_ptr];
	default:
		break;
	}
}


void _cpu_0x1(CPU* const self, const Instruction* const instruction) {
	if (!self || !instruction) {
		return;
	}

	self->pc = instruction_get_nnn(instruction);
}


void _cpu_0x2(CPU* const self, const Instruction* const instruction) {
	if (!self || !instruction) {
		return;
	}

	self->stack[self->stack_ptr] = self->pc;
	self->stack_ptr++;
	self->pc = instruction_get_nnn(instruction);
}


void _cpu_0x3(CPU* const self, const Instruction* const instruction) {
	if (!self || !instruction) {
		return;
	}

	const word nn = instruction_get_nn(instruction);
	const byte x  = instruction_get_x(instruction);

	if (self->v[x] == nn) {
		self->pc += 2;
	}
}


void _cpu_0x4(CPU* const self, const Instruction* const instruction) {
	if (!self || !instruction) {
		return;
	}

	const word nn = instruction_get_nn(instruction);
	const byte x = instruction_get_x(instruction);

	if (self->v[x] != nn) {
		self->pc += 2;
	}
}


void _cpu_0x5(CPU* const self, const Instruction* const instruction) {
	if (!self || !instruction) {
		return;
	}

	if (instruction_get_n(instruction) != 0) {
		return;
	}

	const byte x = instruction_get_x(instruction);
	const byte y = instruction_get_y(instruction);

	if (self->v[x] == self->v[y]) {
		self->pc += 2;
	}
}


void _cpu_0x6(CPU* const self, const Instruction* const instruction) {
	if (!self || !instruction) {
		return;
	}

	const word nn = instruction_get_nn(instruction);
	const byte x  = instruction_get_x(instruction);
	
	self->v[x] = nn;
}


void _cpu_0x7(CPU* const self, const Instruction* const instruction) {
	if (!self || !instruction) {
		return;
	}

	const word nn = instruction_get_nn(instruction);
	const byte x = instruction_get_x(instruction);

	self->v[x] += nn;
}


void _cpu_0x8(CPU* const self, const Instruction* const instruction) {
	if (!self || !instruction) {
		return;
	}

	const byte x = instruction_get_x(instruction);
	const byte y = instruction_get_y(instruction);

	switch (instruction_get_n(instruction)) {
	case 0x0:
		self->v[x] = self->v[y];
		break;
	case 0x1:
		self->v[x] |= self->v[y];
		self->v[0xF] = 0;
		break;
	case 0x2:
		self->v[x] &= self->v[y];
		self->v[0xF] = 0;
		break;
	case 0x3:
		self->v[x] &= self->v[y];
		self->v[0xF] = 0;
		break;
	case 0x4:
		self->v[0xF] = (word)(self->v[x] + self->v[y]) > 255;
		self->v[x] += self->v[y];
		break;
	case 0x5:
		self->v[0xF] = self->v[y] <= self->v[x];
		self->v[x] -= self->v[y];
		break;
	case 0x6:
		self->v[0xF] = self->v[x] & 0x1;
		self->v[x] >>= 1;
		break;
	case 0x7:
		self->v[0xF] = self->v[x] <= self->v[y];
		self->v[x] = self->v[y] - self->v[x];
		break;
	case 0xE:
		self->v[0xF] = (self->v[x] & 0x80) >> 7;
		self->v[x] <<= 1;
		break;
	default:
		/* wrong opcode */
		break;
	}
}


void _cpu_0x9(CPU* const self, const Instruction* const instruction) {
	if (!self || !instruction) {
		return;
	}

	const byte x = instruction_get_x(instruction);
	const byte y = instruction_get_y(instruction);

	if (self->v[x] != self->v[y]) {
		self->pc += 2;
	}
}


void _cpu_0xA(CPU* const self, const Instruction* const instruction) {
	if (!self || !instruction) {
		return;
	}

	self->i = instruction_get_nnn(instruction);
}


void _cpu_0xB(CPU* const self, const Instruction* const instruction) {
	if (!self || !instruction) {
		return;
	}

	self->pc = instruction_get_nnn(instruction) + self->v[0];
}


void _cpu_0xC(CPU* const self, const Instruction* const instruction) {
	if (!self || !instruction) {
		return;
	}

	const byte nn = instruction_get_nn(instruction);
	const byte x  = instruction_get_x(instruction);

	self->v[x] = (byte)(rand() % 255) & nn;
}


void _cpu_0xD(CPU* const self, const Instruction* const instruction) {
	if (!self || !instruction) {
		return;
	}

	// TODO screen
}


void _cpu_0xE(CPU* const self, const Instruction* const instruction) {
	if (!self || !instruction) {
		return;
	}

	// TODO keyboard
}


void _cpu_0xF(CPU* const self, const Instruction* const instruction) {
	if (!self || !instruction) {
		return;
	}

	// TODO keyboard
}
