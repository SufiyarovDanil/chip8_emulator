set(INCLUDE_WINDOW_PATH "${CMAKE_SOURCE_DIR}/include/window")
set(SRC_WINDOW_PATH     "${CMAKE_SOURCE_DIR}/src/window")

#include_directories(${INCLUDE_WINDOW_PATH})

set(
	SRCS
	"${SRCS}"
	"${SRC_WINDOW_PATH}/window.c"
	PARENT_SCOPE
)
