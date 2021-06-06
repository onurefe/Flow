cmake_minimum_required(VERSION 3.8)
project(flashsimulator VERSION 0.1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

add_executable(test_main test_main.c)

add_library(demodulation demodulation.c demodulation.h defines.h)
add_library(complex complex.c complex.h)
target_link_libraries(test_main m complex demodulation)