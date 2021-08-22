cmake_minimum_required(VERSION 3.16)

project(TextRender)

# Gather all cpp files
file(GLOB_RECURSE SOURCES "*.cpp" "*h")

# Build static library from sources
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Use C++17 features
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Link libraries
target_link_libraries(${PROJECT_NAME} DisplayScene)
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} freetype)
target_link_libraries(${PROJECT_NAME} glm)
target_link_libraries(${PROJECT_NAME} glew_s)

# Include header files
target_include_directories(${PROJECT_NAME} PRIVATE "${DisplayScene_SOURCE_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${glew_SOURCE_DIR}/../../include")

message("${glew_SOURCE_DIR}/../../include")

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

# Output destination for library
install(TARGETS ${PROJECT_NAME} DESTINATION bin/Scenes)