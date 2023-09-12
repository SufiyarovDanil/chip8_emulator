#ifndef CPU_H
#define CPU_H

typedef struct CPU CPU;

/* CPU constructor */
CPU* cpu_new();

/* CPU destructor */
void cpu_kill(CPU* const self);

//void cpu_set_i(CPU* const self, const byte i);

//byte cpu_get_i(CPU* const self);

void cpu_exec_instruction(CPU* const self, const word opcode);

#endif // CPU_H
