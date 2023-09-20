cmake_minimum_required (VERSION 3.8)

project ("chip8_emulator")

set(GLFW_DIR "dependencies/glfw-3.3.8")

add_subdirectory(${GLFW_DIR})

add_executable (
	${PROJECT_NAME}
	"src/main.c"
	"src/machine/emulator.c"
	"src/machine/emulator.h"
	"src/machine/core/cpu.c"
	"src/machine/core/cpu.h"
	"src/machine/core/instruction.c"
	"src/machine/core/instruction.h"
	"src/machine/core/ram.h"
	"src/machine/core/ram.c"
	"src/machine/core/defs.h"
	"src/machine/core/rom.h"
	"src/machine/core/rom.c" 
	"src/machine/graphics/display.h"
	"src/machine/graphics/display.c"
	"src/machine/input/keypad.h"
	"src/machine/input/keypad.c"
 "src/window/window.h" "src/window/window.c" "src/app.c" "src/app.h")

target_link_libraries(${PROJECT_NAME} glfw)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()
