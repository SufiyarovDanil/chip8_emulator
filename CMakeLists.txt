cmake_minimum_required (VERSION 3.8)

project ("chip8_emulator")

add_executable (${PROJECT_NAME} "src/main.c" "src/core/cpu.c" "src/core/cpu.h" "src/core/instruction.c" "src/core/instruction.h" "src/core/ram.h" "src/core/ram.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()
