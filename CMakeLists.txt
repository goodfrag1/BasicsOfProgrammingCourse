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
        "Libs/string/tasks/7 task/printWordsOfStringReverse.c"
        "Libs/string/tasks/8 task/countWordsPalindromes.c"
        "Libs/string/tasks/9 task/mergeTwoStrings.c"
        "Libs/string/tasks/10 task/reverseWordsInString.c"
        "Libs/string/tasks/11 task/printWordBeforeFirstWordWithA.c"
        "Libs/string/tasks/12 task/getLastWordFromFirstStringIsInSecondString.c"
        "Libs/string/tasks/13 task/isStringHaveEqualWords.c"
        "Libs/string/tasks/14 task/isWordsContainsSameLetters.c"
        "Libs/string/tasks/15 task/getStringOfWordsDiffOfLastWord.c"
        "Libs/string/tasks/16 task/getLastWordFromFirstStringIsInSecondString.c"
        "Libs/string/tasks/17 task/deleteWordsEqualLast.c"
        "Libs/string/tasks/19 task/isEveryLetterInString.c"
        "Libs/string/tasks/18 task/completeStringWithLessWords.c"
        )

target_link_libraries(project str)
