cmake_minimum_required(VERSION 3.16)

# Include header files
include_directories("${HelloWorld_SOURCE_DIR}/include")
include_directories("${gtest_SOURCE_DIR}/include")

# Gather all test cpp files
file(GLOB_RECURSE SOURCES "*.cpp")

# Build static library from sources
add_executable(${PROJECT_NAME}Test ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME}Test ${PROJECT_NAME}Lib)
target_link_libraries(${PROJECT_NAME}Test gtest_main)

# Output destination for library
install(TARGETS ${PROJECT_NAME}Test DESTINATION test)