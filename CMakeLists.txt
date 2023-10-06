cmake_minimum_required (VERSION 3.8)

project("chip8_emulator" LANGUAGES C)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(unofficial-nativefiledialog CONFIG REQUIRED)

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
	"src/window/window.h"
	"src/window/window.c"
	"src/app.c"
	"src/app.h")

target_link_libraries(${PROJECT_NAME} PRIVATE
	glfw
	glad::glad
	unofficial::nativefiledialog::nfd)
