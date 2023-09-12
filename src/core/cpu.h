#ifndef CPU_H
#define CPU_H
#include "defs.h"

#define CPU_DATA_REGISTERS_COUNT 0x10
#define CPU_STACK_SIZE 0xC
#define CPU_ENTRY_POINT 0x200


typedef struct CPU CPU;

/* CPU constructor */
CPU* cpu_new();

/* CPU destructor */
void cpu_kill(CPU* const self);

void cpu_exec_instruction(CPU* const self, const word opcode);

#endif // CPU_H
