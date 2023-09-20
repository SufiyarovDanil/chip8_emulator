#ifndef WINDOW_H
#define WINDOW_H

typedef struct window_s window_t;

typedef struct GLFWwindow GLFWwindow;

/* window constructor */
window_t* window_new(const char* const title, int width, int height);

/* window destructor */
void window_kill(window_t* const self);

/* retrns GLFWwindow pointer */
GLFWwindow* window_get_raw(window_t* const self);

#endif // WINDOW_H
