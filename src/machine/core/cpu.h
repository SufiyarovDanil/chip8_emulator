#ifndef CPU_H
#define CPU_H

#include "ram.h"

#define CPU_DATA_REGISTERS_COUNT 0x10
#define CPU_STACK_SIZE 0xC
#define CPU_ENTRY_POINT 0x200


typedef struct cpu_s cpu_t;

/* CPU constructor */
cpu_t* cpu_new();

/* CPU destructor */
void cpu_kill(cpu_t* const self);

void cpu_exec_instruction(cpu_t* const self, ram_t* const ram);

#endif // CPU_H
