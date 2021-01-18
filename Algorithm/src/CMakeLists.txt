cmake_minimum_required(VERSION 3.18)

# Include header files
include_directories("${DataStructure_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/include")

# Gather all cpp files
file(GLOB_RECURSE SOURCES "*.cpp")

# Build static library from sources
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Output destination for library
install(TARGETS ${PROJECT_NAME} DESTINATION bin)