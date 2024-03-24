set(INCLUDE_MACHINE_PATH "${CMAKE_SOURCE_DIR}/include/machine")
set(SRC_MACHINE_PATH     "${CMAKE_SOURCE_DIR}/src/machine")

#include_directories(${INCLUDE_MACHINE_PATH})

set(
	SRCS
	"${SRCS}"
	"${SRC_MACHINE_PATH}/emulator.c"
	"${SRC_MACHINE_PATH}/core/cpu.c"
	"${SRC_MACHINE_PATH}/core/instruction.c"
	"${SRC_MACHINE_PATH}/core/ram.c"
	"${SRC_MACHINE_PATH}/core/rom.c"
	"${SRC_MACHINE_PATH}/graphics/display.c"
	"${SRC_MACHINE_PATH}/input/keypad.c"
	PARENT_SCOPE
)
