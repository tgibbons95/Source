cmake_minimum_required(VERSION 3.18)

set(CURRENT_PROJECT "${PROJECT_NAME}Lib")

# Include header files
include_directories("${Display_SOURCE_DIR}/include")
include_directories("${GLFW_SOURCE_DIR}/deps")

# Gather all cpp files
file(GLOB_RECURSE SOURCES "*.cpp")
set(GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad/gl.h"
            "${GLFW_SOURCE_DIR}/deps/glad_gl.c")

# Build static library from sources
add_library(${CURRENT_PROJECT} ${SOURCES})

# Link libraries
target_link_libraries(${CURRENT_PROJECT} glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(${CURRENT_PROJECT} OpenGL::GL)

# Output destination for library
install(TARGETS ${CURRENT_PROJECT} DESTINATION lib)