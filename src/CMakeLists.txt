set(INCLUDE_PATH "${CMAKE_SOURCE_DIR}/include")
set(SRC_PATH     "${CMAKE_SOURCE_DIR}/src")

#include_directories(${INCLUDE_PATH})

add_subdirectory("${SRC_PATH}/machine")
add_subdirectory("${SRC_PATH}/window")

set(
	SRCS
	"${SRCS}"
	"${SRC_PATH}/main.c"
	"${SRC_PATH}/app.c"
	PARENT_SCOPE
)
