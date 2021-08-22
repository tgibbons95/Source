cmake_minimum_required(VERSION 3.16)
project(DisplayManager)

add_subdirectory(src)

install(DIRECTORY "include/"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
        
install(DIRECTORY "data/"
        DESTINATION "data")