cmake_minimum_required(VERSION 3.16)
project(DynamicLoadDllHelloWorldDll)

# Gather all cpp files
file(GLOB_RECURSE SOURCES "*.cpp" "*h")

# Build static library from sources
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Use C++17 features
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Output destination for library
install(TARGETS ${PROJECT_NAME} DESTINATION bin)