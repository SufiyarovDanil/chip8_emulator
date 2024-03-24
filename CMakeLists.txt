cmake_minimum_required (VERSION 3.8)

project("chip8_emulator" LANGUAGES C)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(unofficial-nativefiledialog CONFIG REQUIRED)

set(SRCS "")

add_subdirectory("src")

add_executable(
	${CMAKE_PROJECT_NAME}
	${SRCS}
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "include")

target_link_libraries(
	${CMAKE_PROJECT_NAME} PRIVATE
	glfw
	glad::glad
	unofficial::nativefiledialog::nfd
)
