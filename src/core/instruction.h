#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "defs.h"

typedef struct Instruction Instruction;

/* Instruction constructor */
Instruction* instruction_new(const byte left_byte, const byte right_byte);

/* Instruction destructor */
void instruction_kill(Instruction* const self);

word instruction_get_opcode(const Instruction* const self);

word instruction_get_nnn(const Instruction* const self);

byte instruction_get_nn(const Instruction* const self);

byte instruction_get_n(const Instruction* const self);

byte instruction_get_x(const Instruction* const self);

byte instruction_get_y(const Instruction* const self);

#endif // INSTRUCTION_H
