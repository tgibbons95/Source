cmake_minimum_required(VERSION 3.16)
project(DataStructure)

add_subdirectory(src)
add_subdirectory(test)

install(DIRECTORY "include/"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")