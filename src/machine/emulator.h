#ifndef EMULATOR_H
#define EMULATOR_H

typedef struct emulator_s emulator_t;

/* emulator constructor */
emulator_t* emulator_new();

/* emulator destructor */
void emulator_kill(emulator_t* const self);

void emulator_start(emulator_t* const self);

#endif // EMULATOR_H
