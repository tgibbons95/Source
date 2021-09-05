cmake_minimum_required(VERSION 3.16)

# Set project name
project(BuildingBlocksLib)

# Gather all cpp files
file(GLOB_RECURSE SOURCES "*.cpp" "*.h")

# Build static library from sources
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Include header files
target_include_directories(${PROJECT_NAME} PUBLIC "${BuildingBlocks_SOURCE_DIR}/include")

# Use C++17 features
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Link libraries

# Output destination for library
install(TARGETS ${PROJECT_NAME} DESTINATION lib)