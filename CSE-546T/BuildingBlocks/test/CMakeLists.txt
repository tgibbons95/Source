cmake_minimum_required(VERSION 3.16)

# Set project name
project(BuildingBlocksTest)

# Gather all test cpp files
file(GLOB_RECURSE SOURCES "*.cpp")

# Build test executables from sources
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} BuildingBlocksLib)
target_link_libraries(${PROJECT_NAME} gtest_main)

# Include header files
include_directories("${BuildingBlocks_SOURCE_DIR}/include")
include_directories("${gtest_SOURCE_DIR}/include")

# Build with C++17
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Add test to run
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

# Output destination for library
install(TARGETS ${PROJECT_NAME} DESTINATION "test")