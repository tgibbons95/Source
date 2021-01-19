cmake_minimum_required(VERSION 3.16)

# Include header files
include_directories("${HelloWorld_SOURCE_DIR}/include")

# Gather all cpp files
file(GLOB_RECURSE SOURCES "*.cpp")

# Build static library from sources
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}Lib)

# Output destination for library
install(TARGETS ${PROJECT_NAME} DESTINATION bin)