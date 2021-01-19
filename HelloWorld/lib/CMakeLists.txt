cmake_minimum_required(VERSION 3.16)

# Include header files
include_directories("${HelloWorld_SOURCE_DIR}/include")

# Gather all cpp files
file(GLOB_RECURSE SOURCES "*.cpp")

# Build static library from sources
add_library(${PROJECT_NAME}Lib STATIC ${SOURCES})

# Output destination for library
install(TARGETS ${PROJECT_NAME}Lib DESTINATION lib)