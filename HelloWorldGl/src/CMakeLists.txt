cmake_minimum_required(VERSION 3.16)

# Include header files
include_directories("${HelloWorldGl_SOURCE_DIR}/include")

# Gather all cpp files
file(GLOB_RECURSE SOURCES "*.cpp")

if (WIN32)
    set(ICON "${GLFW_SOURCE_DIR}/examples/glfw.rc")
elseif (APPLE)
    set(ICON "${GLFW_SOURCE_DIR}/examples/glfw.icns")
endif()

# Build static library from sources
add_executable(${PROJECT_NAME} WIN32 ${SOURCES} ${ICON})

# Link libraries
target_link_libraries(${PROJECT_NAME} glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

if (MSVC)
    # Tell MSVC to use main instead of WinMain for Windows subsystem executables
    set_target_properties(${PROJECT_NAME} PROPERTIES
                          LINK_FLAGS "/ENTRY:mainCRTStartup")
endif()

# Output destination for library
install(TARGETS ${PROJECT_NAME} DESTINATION bin)