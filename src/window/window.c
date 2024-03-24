#include "window/window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>


const GLchar* const vertex_shader_source =
"#version 330 core\n"
"layout (location = 0) in vec2 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, 0.f, 1.f);\n"
"}";

const GLchar* const fragment_shader_source =
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}";


struct window_s {
	GLFWwindow* gl_window;
	int         width;
	int         height;
	GLuint      shader_program;
};


window_t* window_new(const char* const title, int width, int height) {
	window_t* window = (window_t*)malloc(sizeof(window_t));

	window->gl_window = glfwCreateWindow(width, height, title, 0, 0);
	window->width = width;
	window->height = height;

	glfwMakeContextCurrent(window->gl_window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		window_kill(window);
		
		return (window_t*)0;
	}

	glViewport(0, 0, width, height);

	window->shader_program = glCreateProgram();
	
	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertex_shader, 1, &vertex_shader_source, 0);
	glCompileShader(vertex_shader);

	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragment_shader, 1, &fragment_shader_source, 0);
	glCompileShader(fragment_shader);

	glAttachShader(window->shader_program, vertex_shader);
	glAttachShader(window->shader_program, fragment_shader);
	glLinkProgram(window->shader_program);
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	return window;
}


void window_kill(window_t* const self) {
	if (!self) {
		return;
	}
	
	glDeleteProgram(self->shader_program);
	glfwDestroyWindow(self->gl_window);
	free(self);
}


void window_redraw(window_t* const self, const display_t* const display) {
	if (!self) {
		return;
	}

	glClearColor(0.f, 0.4f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

	const size_t white_pixel_count = display_count_set_pixels(display);
	const word display_size = display_get_size(display);
	const byte layout = 2; // x, y coords
	const byte quad_vert_count = 6;
	const byte quad_size = layout * quad_vert_count;
	const GLfloat quad_side_x = (GLfloat)self->width / DISPLAY_WIDTH * 2.f;
	const GLfloat quad_side_y = (GLfloat)self->height / DISPLAY_HEIGHT * 2.f;
	const size_t arr_size = white_pixel_count * quad_size;
	GLfloat* verticies = (GLfloat*)malloc(sizeof(GLfloat) * arr_size);

	size_t vert_index = 0;

	for (word i = 0; i < display_size; i++) {
		if (!display_read_pixel(display, i)) {
			continue;
		}

		const GLfloat x = quad_side_x * (i % DISPLAY_WIDTH);
		const GLfloat y = quad_side_y * (i / DISPLAY_WIDTH);
		const GLfloat x_norm = 1.f / self->width;
		const GLfloat y_norm = 1.f / self->height;

		verticies[vert_index + 0]  = x * x_norm - 1.f;                 // vert 1: X
		verticies[vert_index + 1]  = 1.f - y * y_norm;                 // vert 1: Y    1---------------2/6
		verticies[vert_index + 2]  = (x + quad_side_x) * x_norm - 1.f; // vert 2: X    |               |
		verticies[vert_index + 3]  = 1.f - y * y_norm;                 // vert 2: Y    |               |
		verticies[vert_index + 4]  = x * x_norm - 1.f;                 // vert 3: X    |               |
		verticies[vert_index + 5]  = 1.f - (y - quad_side_y) * y_norm; // vert 3: Y    |               |
		verticies[vert_index + 6]  = x * x_norm - 1.f;                 // vert 4: X    |               |
		verticies[vert_index + 7]  = 1.f - (y - quad_side_y) * y_norm; // vert 4: Y    |               |
		verticies[vert_index + 8]  = (x + quad_side_x) * x_norm - 1.f; // vert 5: X    |               |
		verticies[vert_index + 9]  = 1.f - (y - quad_side_y) * y_norm; // vert 5: Y    |               |
		verticies[vert_index + 10] = (x + quad_side_x) * x_norm - 1.f; // vert 6: X    3/4-------------5
		verticies[vert_index + 11] = 1.f - y * y_norm;                 // vert 6: Y
		vert_index += quad_size;
	}

	GLuint vertex_buffer = 0;

	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * arr_size, verticies, GL_DYNAMIC_DRAW);

	GLuint vertex_array = 0;
	glGenVertexArrays(1, &vertex_array);
	glBindVertexArray(vertex_array);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);

	glUseProgram(self->shader_program);

	glDrawArrays(GL_TRIANGLES, 0, white_pixel_count * quad_vert_count);

	glDeleteBuffers(1, &vertex_buffer);
	glDeleteVertexArrays(1, &vertex_array);
	free(verticies);
	glfwSwapBuffers(self->gl_window);
}


GLFWwindow* window_get_raw(window_t* const self) {
	if (!self) {
		return (GLFWwindow*)0;
	}

	return self->gl_window;
}
