cmake_minimum_required(VERSION 3.16)

set(CURRENT_PROJECT "${PROJECT_NAME}Demo")

# Include header files
include_directories("${Display_SOURCE_DIR}/include")
include_directories("${GLFW_SOURCE_DIR}/deps")

# Gather all cpp files
file(GLOB_RECURSE SOURCES "*.cpp")
set(GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad/gl.h"
            "${GLFW_SOURCE_DIR}/deps/glad_gl.c")
   
if (WIN32)
    set(ICON "${GLFW_SOURCE_DIR}/examples/glfw.rc")
elseif (APPLE)
    set(ICON "${GLFW_SOURCE_DIR}/examples/glfw.icns")
endif()

   
# Build static library from sources
add_executable(${CURRENT_PROJECT} WIN32 ${SOURCES} ${ICON} ${GLAD_GL})

# Link libraries
target_link_libraries(${CURRENT_PROJECT} glfw)
target_link_libraries(${CURRENT_PROJECT} ${PROJECT_NAME}Lib)

find_package(OpenGL REQUIRED)
target_link_libraries(${CURRENT_PROJECT} OpenGL::GL)

if (MSVC)
    # Tell MSVC to use main instead of WinMain for Windows subsystem executables
    set_target_properties(${CURRENT_PROJECT} PROPERTIES
                          LINK_FLAGS "/ENTRY:mainCRTStartup")
endif()

# Output destination for library
install(TARGETS ${CURRENT_PROJECT} DESTINATION bin)