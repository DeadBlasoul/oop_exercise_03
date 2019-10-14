# CMakeList.txt : CMake project for oop-lab-01, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project (LabWork)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

include(config)
enable_testing()

add_subdirectory(app)
add_subdirectory(src)
add_subdirectory(tests)
