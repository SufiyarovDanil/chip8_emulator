#include "machine/core/instruction.h"
#include <stdlib.h>
#include <memory.h>


struct instruction_s {
	word opcode;
	word nnn;       // 12 bit addr constant
	byte nn;        // 8 bit constant
	byte n;         // 4 bit constant
	byte x;         // 4 bit register identifier
	byte y;         // 4 bit register identifier
};


instruction_t* instruction_new(const byte left_byte, const byte right_byte) {
	instruction_t* const instruction = (instruction_t*)malloc(sizeof(instruction_t));

	const word opcode = ((word)left_byte << 8) | ((word)right_byte);

	instruction->opcode	= opcode;
	instruction->nnn	= opcode & 0xFFF;
	instruction->nn		= opcode & 0xFF;
	instruction->n		= opcode & 0xF;
	instruction->x		= (opcode >> 8) & 0xF;
	instruction->y		= (opcode >> 4) & 0xF;

	return instruction;
}


void instruction_kill(instruction_t* const self) {
	if (!self) {
		return;
	}

	free(self);
}


word instruction_get_opcode(const instruction_t* const self) {
	if (!self) {
		return 0;
	}

	return self->opcode;
}


word instruction_get_nnn(const instruction_t* const self) {
	if (!self) {
		return 0;
	}

	return self->nnn;
}


byte instruction_get_nn(const instruction_t* const self) {
	if (!self) {
		return 0;
	}

	return self->nn;
}


byte instruction_get_n(const instruction_t* const self) {
	if (!self) {
		return 0;
	}

	return self->n;
}


byte instruction_get_x(const instruction_t* const self) {
	if (!self) {
		return 0;
	}

	return self->x;
}


byte instruction_get_y(const instruction_t* const self) {
	if (!self) {
		return 0;
	}

	return self->y;
}
