#ifndef CPU_H
#define CPU_H

#include "../emulator.h"

#define CPU_DATA_REGISTERS_COUNT 0x10
#define CPU_STACK_SIZE 0xC
#define CPU_ENTRY_POINT 0x200


typedef struct cpu_s cpu_t;

/* CPU constructor */
cpu_t* cpu_new(emulator_t* const owner);

/* CPU destructor */
void cpu_kill(cpu_t* const self);

void cpu_make_step(cpu_t* const self);

#endif // CPU_H
