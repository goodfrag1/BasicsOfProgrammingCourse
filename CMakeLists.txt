cmake_minimum_required(VERSION 3.20)
project(Laba_5b C)

set(CMAKE_C_STANDARD 11)

add_executable(project main.c)


add_library(str Libs/string/string_.h Libs/string/string_.c
        "Libs/string/tasks/1 task/removeNonLetters.c"
        "Libs/string/tasks/2 task/removeExtraSpaces.c"
        "Libs/string/tasks/3 task/digitToStart.c"
        "Libs/string/tasks/4 task/changeDigitsOnSpacesByValue.c"
        "Libs/string/tasks/5 task/replace.c"
        "Libs/string/tasks/6 task/checkSortingInString.c"
        )

target_link_libraries(project str)
