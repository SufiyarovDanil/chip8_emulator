#ifndef CPU_H
#define CPU_H
#include "defs.h"

typedef struct CPU CPU;

/* CPU constructor */
CPU* cpu_new();

/* CPU destructor */
void cpu_kill(CPU* const self);

void cpu_exec_instruction(CPU* const self, const word opcode);

#endif // CPU_H
