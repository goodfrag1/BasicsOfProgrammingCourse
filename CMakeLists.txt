cmake_minimum_required(VERSION 3.20)
project(Laba_5b C)

set(CMAKE_C_STANDARD 11)

add_executable(project main.c)


add_library(str Libs/string/string_.h Libs/string/string_.c
        "Libs/string/tasks/1 task/removeNonLetters.c"
        )

target_link_libraries(project str)
