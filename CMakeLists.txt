cmake_minimum_required(VERSION 3.20)
project(Laba_5b C)

set(CMAKE_C_STANDARD 11)

add_executable(Laba_5b main.c Libs/algorithms/functions/function.c Libs/algorithms/functions/function.h Libs/algorithms/algorithm.c Libs/algorithms/algorithm.h)


add_subdirectory(libs)
target_link_libraries(Laba_5b algorithms)
