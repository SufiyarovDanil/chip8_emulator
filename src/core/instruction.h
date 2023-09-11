#ifndef INSTRUCTION_H
#define INSTRUCTION_H

typedef unsigned char byte;

typedef struct Instruction Instruction;

/* Instruction constructor */
Instruction* instruction_new(const byte left_byte, const byte right_byte);

/* Instruction destructor */
void instruction_kill(Instruction* const self);

#endif // INSTRUCTION_H
