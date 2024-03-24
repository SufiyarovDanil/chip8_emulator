#ifndef WINDOW_H
#define WINDOW_H

#include "../machine/graphics/display.h"


typedef struct window_s window_t;

typedef struct GLFWwindow GLFWwindow;

/* window constructor */
window_t* window_new(const char* const title, int width, int height);

/* window destructor */
void window_kill(window_t* const self);

void window_redraw(window_t* const self, const display_t* const display);

/* retrns GLFWwindow pointer */
GLFWwindow* window_get_raw(window_t* const self);

#endif // WINDOW_H
