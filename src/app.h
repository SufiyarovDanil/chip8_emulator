#ifndef APP_H
#define APP_H

typedef struct app_s app_t;

/* app constructor */
app_t* app_new();

/* app destructor */
void app_kill(app_t* const self);

void app_run(app_t* const self);

#endif // APP_H
