#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "defs.h"

typedef struct instruction_s instruction_t;

/* Instruction constructor */
instruction_t* instruction_new(const byte left_byte, const byte right_byte);

/* Instruction destructor */
void instruction_kill(instruction_t* const self);

word instruction_get_opcode(const instruction_t* const self);

word instruction_get_nnn(const instruction_t* const self);

byte instruction_get_nn(const instruction_t* const self);

byte instruction_get_n(const instruction_t* const self);

byte instruction_get_x(const instruction_t* const self);

byte instruction_get_y(const instruction_t* const self);

#endif // INSTRUCTION_H
