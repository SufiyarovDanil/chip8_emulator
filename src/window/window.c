#include "window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <memory.h>


struct window_s {
	GLFWwindow* gl_window;
};


window_t* window_new(const char* const title, int width, int height) {
	window_t* window = (window_t*)malloc(sizeof(window_t));

	window->gl_window = glfwCreateWindow(width, height, title, 0, 0);

	return window;
}


void window_kill(window_t* const self) {
	if (!self) {
		return;
	}

	glfwDestroyWindow(self->gl_window);
	free(self);
}


void window_redraw(window_t* const self) {
	if (!self) {
		return;
	}

	glClear(GL_COLOR_BUFFER_BIT);

	// ...

	glfwSwapBuffers(self->gl_window);
}


GLFWwindow* window_get_raw(window_t* const self) {
	if (!self) {
		return (GLFWwindow*)0;
	}

	return self->gl_window;
}
