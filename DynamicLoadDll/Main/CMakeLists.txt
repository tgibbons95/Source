cmake_minimum_required(VERSION 3.16)
project(DynamicLoadDllMain)

# Gather all cpp files
file(GLOB_RECURSE SOURCES "*.cpp" "*h")

# Build static library from sources
add_executable(${PROJECT_NAME} ${SOURCES})

# Use C++17 features
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Output destination for library
install(TARGETS ${PROJECT_NAME} DESTINATION bin)