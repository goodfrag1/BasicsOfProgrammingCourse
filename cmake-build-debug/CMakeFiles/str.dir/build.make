# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User-GDFG\CLionProjects\Laba_5b

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User-GDFG\CLionProjects\Laba_5b\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/str.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/str.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/str.dir/flags.make

CMakeFiles/str.dir/Libs/string/string_.c.obj: CMakeFiles/str.dir/flags.make
CMakeFiles/str.dir/Libs/string/string_.c.obj: ../Libs/string/string_.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User-GDFG\CLionProjects\Laba_5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/str.dir/Libs/string/string_.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\str.dir\Libs\string\string_.c.obj -c C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\string_.c

CMakeFiles/str.dir/Libs/string/string_.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/str.dir/Libs/string/string_.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\string_.c > CMakeFiles\str.dir\Libs\string\string_.c.i

CMakeFiles/str.dir/Libs/string/string_.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/str.dir/Libs/string/string_.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\string_.c -o CMakeFiles\str.dir\Libs\string\string_.c.s

CMakeFiles/str.dir/Libs/string/tasks/1_task/removeNonLetters.c.obj: CMakeFiles/str.dir/flags.make
CMakeFiles/str.dir/Libs/string/tasks/1_task/removeNonLetters.c.obj: ../Libs/string/tasks/1\ task/removeNonLetters.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User-GDFG\CLionProjects\Laba_5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/str.dir/Libs/string/tasks/1_task/removeNonLetters.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\str.dir\Libs\string\tasks\1_task\removeNonLetters.c.obj -c "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\1 task\removeNonLetters.c"

CMakeFiles/str.dir/Libs/string/tasks/1_task/removeNonLetters.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/str.dir/Libs/string/tasks/1_task/removeNonLetters.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\1 task\removeNonLetters.c" > CMakeFiles\str.dir\Libs\string\tasks\1_task\removeNonLetters.c.i

CMakeFiles/str.dir/Libs/string/tasks/1_task/removeNonLetters.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/str.dir/Libs/string/tasks/1_task/removeNonLetters.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\1 task\removeNonLetters.c" -o CMakeFiles\str.dir\Libs\string\tasks\1_task\removeNonLetters.c.s

CMakeFiles/str.dir/Libs/string/tasks/2_task/removeExtraSpaces.c.obj: CMakeFiles/str.dir/flags.make
CMakeFiles/str.dir/Libs/string/tasks/2_task/removeExtraSpaces.c.obj: ../Libs/string/tasks/2\ task/removeExtraSpaces.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User-GDFG\CLionProjects\Laba_5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/str.dir/Libs/string/tasks/2_task/removeExtraSpaces.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\str.dir\Libs\string\tasks\2_task\removeExtraSpaces.c.obj -c "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\2 task\removeExtraSpaces.c"

CMakeFiles/str.dir/Libs/string/tasks/2_task/removeExtraSpaces.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/str.dir/Libs/string/tasks/2_task/removeExtraSpaces.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\2 task\removeExtraSpaces.c" > CMakeFiles\str.dir\Libs\string\tasks\2_task\removeExtraSpaces.c.i

CMakeFiles/str.dir/Libs/string/tasks/2_task/removeExtraSpaces.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/str.dir/Libs/string/tasks/2_task/removeExtraSpaces.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\2 task\removeExtraSpaces.c" -o CMakeFiles\str.dir\Libs\string\tasks\2_task\removeExtraSpaces.c.s

CMakeFiles/str.dir/Libs/string/tasks/3_task/digitToStart.c.obj: CMakeFiles/str.dir/flags.make
CMakeFiles/str.dir/Libs/string/tasks/3_task/digitToStart.c.obj: ../Libs/string/tasks/3\ task/digitToStart.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User-GDFG\CLionProjects\Laba_5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/str.dir/Libs/string/tasks/3_task/digitToStart.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\str.dir\Libs\string\tasks\3_task\digitToStart.c.obj -c "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\3 task\digitToStart.c"

CMakeFiles/str.dir/Libs/string/tasks/3_task/digitToStart.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/str.dir/Libs/string/tasks/3_task/digitToStart.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\3 task\digitToStart.c" > CMakeFiles\str.dir\Libs\string\tasks\3_task\digitToStart.c.i

CMakeFiles/str.dir/Libs/string/tasks/3_task/digitToStart.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/str.dir/Libs/string/tasks/3_task/digitToStart.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\3 task\digitToStart.c" -o CMakeFiles\str.dir\Libs\string\tasks\3_task\digitToStart.c.s

CMakeFiles/str.dir/Libs/string/tasks/4_task/changeDigitsOnSpacesByValue.c.obj: CMakeFiles/str.dir/flags.make
CMakeFiles/str.dir/Libs/string/tasks/4_task/changeDigitsOnSpacesByValue.c.obj: ../Libs/string/tasks/4\ task/changeDigitsOnSpacesByValue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User-GDFG\CLionProjects\Laba_5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/str.dir/Libs/string/tasks/4_task/changeDigitsOnSpacesByValue.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\str.dir\Libs\string\tasks\4_task\changeDigitsOnSpacesByValue.c.obj -c "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\4 task\changeDigitsOnSpacesByValue.c"

CMakeFiles/str.dir/Libs/string/tasks/4_task/changeDigitsOnSpacesByValue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/str.dir/Libs/string/tasks/4_task/changeDigitsOnSpacesByValue.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\4 task\changeDigitsOnSpacesByValue.c" > CMakeFiles\str.dir\Libs\string\tasks\4_task\changeDigitsOnSpacesByValue.c.i

CMakeFiles/str.dir/Libs/string/tasks/4_task/changeDigitsOnSpacesByValue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/str.dir/Libs/string/tasks/4_task/changeDigitsOnSpacesByValue.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\4 task\changeDigitsOnSpacesByValue.c" -o CMakeFiles\str.dir\Libs\string\tasks\4_task\changeDigitsOnSpacesByValue.c.s

CMakeFiles/str.dir/Libs/string/tasks/5_task/replace.c.obj: CMakeFiles/str.dir/flags.make
CMakeFiles/str.dir/Libs/string/tasks/5_task/replace.c.obj: ../Libs/string/tasks/5\ task/replace.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User-GDFG\CLionProjects\Laba_5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/str.dir/Libs/string/tasks/5_task/replace.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\str.dir\Libs\string\tasks\5_task\replace.c.obj -c "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\5 task\replace.c"

CMakeFiles/str.dir/Libs/string/tasks/5_task/replace.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/str.dir/Libs/string/tasks/5_task/replace.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\5 task\replace.c" > CMakeFiles\str.dir\Libs\string\tasks\5_task\replace.c.i

CMakeFiles/str.dir/Libs/string/tasks/5_task/replace.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/str.dir/Libs/string/tasks/5_task/replace.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\5 task\replace.c" -o CMakeFiles\str.dir\Libs\string\tasks\5_task\replace.c.s

CMakeFiles/str.dir/Libs/string/tasks/6_task/checkSortingInString.c.obj: CMakeFiles/str.dir/flags.make
CMakeFiles/str.dir/Libs/string/tasks/6_task/checkSortingInString.c.obj: ../Libs/string/tasks/6\ task/checkSortingInString.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User-GDFG\CLionProjects\Laba_5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/str.dir/Libs/string/tasks/6_task/checkSortingInString.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\str.dir\Libs\string\tasks\6_task\checkSortingInString.c.obj -c "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\6 task\checkSortingInString.c"

CMakeFiles/str.dir/Libs/string/tasks/6_task/checkSortingInString.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/str.dir/Libs/string/tasks/6_task/checkSortingInString.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\6 task\checkSortingInString.c" > CMakeFiles\str.dir\Libs\string\tasks\6_task\checkSortingInString.c.i

CMakeFiles/str.dir/Libs/string/tasks/6_task/checkSortingInString.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/str.dir/Libs/string/tasks/6_task/checkSortingInString.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\6 task\checkSortingInString.c" -o CMakeFiles\str.dir\Libs\string\tasks\6_task\checkSortingInString.c.s

CMakeFiles/str.dir/Libs/string/tasks/7_task/printWordsOfStringReverse.c.obj: CMakeFiles/str.dir/flags.make
CMakeFiles/str.dir/Libs/string/tasks/7_task/printWordsOfStringReverse.c.obj: ../Libs/string/tasks/7\ task/printWordsOfStringReverse.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User-GDFG\CLionProjects\Laba_5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/str.dir/Libs/string/tasks/7_task/printWordsOfStringReverse.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\str.dir\Libs\string\tasks\7_task\printWordsOfStringReverse.c.obj -c "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\7 task\printWordsOfStringReverse.c"

CMakeFiles/str.dir/Libs/string/tasks/7_task/printWordsOfStringReverse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/str.dir/Libs/string/tasks/7_task/printWordsOfStringReverse.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\7 task\printWordsOfStringReverse.c" > CMakeFiles\str.dir\Libs\string\tasks\7_task\printWordsOfStringReverse.c.i

CMakeFiles/str.dir/Libs/string/tasks/7_task/printWordsOfStringReverse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/str.dir/Libs/string/tasks/7_task/printWordsOfStringReverse.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\7 task\printWordsOfStringReverse.c" -o CMakeFiles\str.dir\Libs\string\tasks\7_task\printWordsOfStringReverse.c.s

CMakeFiles/str.dir/Libs/string/tasks/8_task/countWordsPalindromes.c.obj: CMakeFiles/str.dir/flags.make
CMakeFiles/str.dir/Libs/string/tasks/8_task/countWordsPalindromes.c.obj: ../Libs/string/tasks/8\ task/countWordsPalindromes.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User-GDFG\CLionProjects\Laba_5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/str.dir/Libs/string/tasks/8_task/countWordsPalindromes.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\str.dir\Libs\string\tasks\8_task\countWordsPalindromes.c.obj -c "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\8 task\countWordsPalindromes.c"

CMakeFiles/str.dir/Libs/string/tasks/8_task/countWordsPalindromes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/str.dir/Libs/string/tasks/8_task/countWordsPalindromes.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\8 task\countWordsPalindromes.c" > CMakeFiles\str.dir\Libs\string\tasks\8_task\countWordsPalindromes.c.i

CMakeFiles/str.dir/Libs/string/tasks/8_task/countWordsPalindromes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/str.dir/Libs/string/tasks/8_task/countWordsPalindromes.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\8 task\countWordsPalindromes.c" -o CMakeFiles\str.dir\Libs\string\tasks\8_task\countWordsPalindromes.c.s

CMakeFiles/str.dir/Libs/string/tasks/10_task/reverseWordsInString.c.obj: CMakeFiles/str.dir/flags.make
CMakeFiles/str.dir/Libs/string/tasks/10_task/reverseWordsInString.c.obj: ../Libs/string/tasks/10\ task/reverseWordsInString.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User-GDFG\CLionProjects\Laba_5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/str.dir/Libs/string/tasks/10_task/reverseWordsInString.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\str.dir\Libs\string\tasks\10_task\reverseWordsInString.c.obj -c "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\10 task\reverseWordsInString.c"

CMakeFiles/str.dir/Libs/string/tasks/10_task/reverseWordsInString.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/str.dir/Libs/string/tasks/10_task/reverseWordsInString.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\10 task\reverseWordsInString.c" > CMakeFiles\str.dir\Libs\string\tasks\10_task\reverseWordsInString.c.i

CMakeFiles/str.dir/Libs/string/tasks/10_task/reverseWordsInString.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/str.dir/Libs/string/tasks/10_task/reverseWordsInString.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\User-GDFG\CLionProjects\Laba_5b\Libs\string\tasks\10 task\reverseWordsInString.c" -o CMakeFiles\str.dir\Libs\string\tasks\10_task\reverseWordsInString.c.s

# Object files for target str
str_OBJECTS = \
"CMakeFiles/str.dir/Libs/string/string_.c.obj" \
"CMakeFiles/str.dir/Libs/string/tasks/1_task/removeNonLetters.c.obj" \
"CMakeFiles/str.dir/Libs/string/tasks/2_task/removeExtraSpaces.c.obj" \
"CMakeFiles/str.dir/Libs/string/tasks/3_task/digitToStart.c.obj" \
"CMakeFiles/str.dir/Libs/string/tasks/4_task/changeDigitsOnSpacesByValue.c.obj" \
"CMakeFiles/str.dir/Libs/string/tasks/5_task/replace.c.obj" \
"CMakeFiles/str.dir/Libs/string/tasks/6_task/checkSortingInString.c.obj" \
"CMakeFiles/str.dir/Libs/string/tasks/7_task/printWordsOfStringReverse.c.obj" \
"CMakeFiles/str.dir/Libs/string/tasks/8_task/countWordsPalindromes.c.obj" \
"CMakeFiles/str.dir/Libs/string/tasks/10_task/reverseWordsInString.c.obj"

# External object files for target str
str_EXTERNAL_OBJECTS =

libstr.a: CMakeFiles/str.dir/Libs/string/string_.c.obj
libstr.a: CMakeFiles/str.dir/Libs/string/tasks/1_task/removeNonLetters.c.obj
libstr.a: CMakeFiles/str.dir/Libs/string/tasks/2_task/removeExtraSpaces.c.obj
libstr.a: CMakeFiles/str.dir/Libs/string/tasks/3_task/digitToStart.c.obj
libstr.a: CMakeFiles/str.dir/Libs/string/tasks/4_task/changeDigitsOnSpacesByValue.c.obj
libstr.a: CMakeFiles/str.dir/Libs/string/tasks/5_task/replace.c.obj
libstr.a: CMakeFiles/str.dir/Libs/string/tasks/6_task/checkSortingInString.c.obj
libstr.a: CMakeFiles/str.dir/Libs/string/tasks/7_task/printWordsOfStringReverse.c.obj
libstr.a: CMakeFiles/str.dir/Libs/string/tasks/8_task/countWordsPalindromes.c.obj
libstr.a: CMakeFiles/str.dir/Libs/string/tasks/10_task/reverseWordsInString.c.obj
libstr.a: CMakeFiles/str.dir/build.make
libstr.a: CMakeFiles/str.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User-GDFG\CLionProjects\Laba_5b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C static library libstr.a"
	$(CMAKE_COMMAND) -P CMakeFiles\str.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\str.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/str.dir/build: libstr.a
.PHONY : CMakeFiles/str.dir/build

CMakeFiles/str.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\str.dir\cmake_clean.cmake
.PHONY : CMakeFiles/str.dir/clean

CMakeFiles/str.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User-GDFG\CLionProjects\Laba_5b C:\Users\User-GDFG\CLionProjects\Laba_5b C:\Users\User-GDFG\CLionProjects\Laba_5b\cmake-build-debug C:\Users\User-GDFG\CLionProjects\Laba_5b\cmake-build-debug C:\Users\User-GDFG\CLionProjects\Laba_5b\cmake-build-debug\CMakeFiles\str.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/str.dir/depend

