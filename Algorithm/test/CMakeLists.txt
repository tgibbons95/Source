cmake_minimum_required(VERSION 3.16)
project(AlgorithmTest)

# Include header files
include_directories("${DataStructure_SOURCE_DIR}/include")
include_directories("${Algorithm_SOURCE_DIR}/include")
include_directories("${gtest_SOURCE_DIR}/include")

# Gather all test cpp files
file(GLOB_RECURSE SOURCES "*.cpp")

# Build static library from sources
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} Algorithm)
target_link_libraries(${PROJECT_NAME} gtest_main)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

# Output destination for library
install(TARGETS ${PROJECT_NAME} DESTINATION test)