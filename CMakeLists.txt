cmake_minimum_required(VERSION 3.20)
project(Laba_5b C)

set(CMAKE_C_STANDARD 11)

add_executable(Laba_5b main.c Libs/algorithms/functions/function.c Libs/algorithms/functions/function.h Libs/algorithms/algorithm.c Libs/algorithms/algorithm.h Libs/data_structures/vector/vector.c Libs/data_structures/vector/vector.h)


add_subdirectory(libs)
target_link_libraries(Laba_5b algorithms)
target_link_libraries(Laba_5b data_structures)
