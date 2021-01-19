cmake_minimum_required(VERSION 3.16)

# Include header files
include_directories("${HelloWorldGl_SOURCE_DIR}/include")

# Gather all cpp files
file(GLOB_RECURSE SOURCES "*.cpp")

# Build static library from sources
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

# Output destination for library
install(TARGETS ${PROJECT_NAME} DESTINATION bin)