cmake_minimum_required(VERSION 3.16)

# Include header files
include_directories("${Algorithm_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/include")

# Gather all cpp files
file(GLOB_RECURSE SOURCES "*.cpp")

# Build static library from sources
add_library(${PROJECT_NAME} STATIC ${SOURCES})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Output destination for library
install(TARGETS ${PROJECT_NAME} DESTINATION bin)