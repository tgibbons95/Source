cmake_minimum_required(VERSION 3.18)
project(HelloWorldGl)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)

install(DIRECTORY "include/"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")