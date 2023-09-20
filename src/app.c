#include "app.h"
#include "machine/emulator.h"
#include "window/window.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>


typedef enum app_state {
	RUNNING,
	PAUSED,
	CLOSED
} app_state;


struct app_s {
	emulator_t* emulator;
	window_t*   window;
	app_state   state;
};


app_t* app_new() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	app_t* app = (app_t*)malloc(sizeof(app_t));

	app->emulator = emulator_new();
	app->window   = window_new("CHIP8", 800, 400);
	app->state    = RUNNING;

	return app;
}


void app_kill(app_t* const self) {
	if (!self) {
		return;
	}

	emulator_kill(self->emulator);
	window_kill(self->window);
	free(self);
	glfwTerminate();
}


void app_run(app_t* const self) {
	if (!self) {
		return;
	}

	emulator_start(self->emulator);

	GLFWwindow* glfw_win = window_get_raw(self->window);

	while (self->state == RUNNING && !glfwWindowShouldClose(glfw_win)) {
		emulator_make_step(self->emulator, glfw_win);
		//window_redraw(self->window);

		const int state = glfwGetKey(glfw_win, GLFW_KEY_ESCAPE);

		if (state == GLFW_PRESS) {
			self->state = CLOSED;
		}

		glfwSwapBuffers(glfw_win);
		glfwPollEvents();
	}
}
