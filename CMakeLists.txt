cmake_minimum_required (VERSION 2.6)

project(HELLO)
find_package(CURL REQUIRED)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

#set(CMAKE_VERBOSE_MAKEFILE on)
add_subdirectory(src)
add_subdirectory(libhello)
add_subdirectory(utf8proc)
