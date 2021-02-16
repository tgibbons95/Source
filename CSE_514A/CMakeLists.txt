cmake_minimum_required(VERSION 3.16)
project(CSE_514)

add_subdirectory(src)
add_subdirectory(test)

install(DIRECTORY "include/"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
        
install(DIRECTORY "data"
        DESTINATION "test")