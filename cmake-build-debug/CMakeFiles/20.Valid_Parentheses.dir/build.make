# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "D:\Program Files (x86)\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files (x86)\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\leetcode c++"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\leetcode c++\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/20.Valid_Parentheses.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/20.Valid_Parentheses.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/20.Valid_Parentheses.dir/flags.make

CMakeFiles/20.Valid_Parentheses.dir/code/5.stack_and_queue/20.Valid_Parentheses.cpp.obj: CMakeFiles/20.Valid_Parentheses.dir/flags.make
CMakeFiles/20.Valid_Parentheses.dir/code/5.stack_and_queue/20.Valid_Parentheses.cpp.obj: ../code/5.stack\ and\ queue/20.Valid_Parentheses.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\leetcode c++\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/20.Valid_Parentheses.dir/code/5.stack_and_queue/20.Valid_Parentheses.cpp.obj"
	"D:\Program Files (x86)\MinGw\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\20.Valid_Parentheses.dir\code\5.stack_and_queue\20.Valid_Parentheses.cpp.obj -c "E:\leetcode c++\code\5.stack and queue\20.Valid_Parentheses.cpp"

CMakeFiles/20.Valid_Parentheses.dir/code/5.stack_and_queue/20.Valid_Parentheses.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/20.Valid_Parentheses.dir/code/5.stack_and_queue/20.Valid_Parentheses.cpp.i"
	"D:\Program Files (x86)\MinGw\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\leetcode c++\code\5.stack and queue\20.Valid_Parentheses.cpp" > CMakeFiles\20.Valid_Parentheses.dir\code\5.stack_and_queue\20.Valid_Parentheses.cpp.i

CMakeFiles/20.Valid_Parentheses.dir/code/5.stack_and_queue/20.Valid_Parentheses.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/20.Valid_Parentheses.dir/code/5.stack_and_queue/20.Valid_Parentheses.cpp.s"
	"D:\Program Files (x86)\MinGw\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\leetcode c++\code\5.stack and queue\20.Valid_Parentheses.cpp" -o CMakeFiles\20.Valid_Parentheses.dir\code\5.stack_and_queue\20.Valid_Parentheses.cpp.s

# Object files for target 20.Valid_Parentheses
20_Valid_Parentheses_OBJECTS = \
"CMakeFiles/20.Valid_Parentheses.dir/code/5.stack_and_queue/20.Valid_Parentheses.cpp.obj"

# External object files for target 20.Valid_Parentheses
20_Valid_Parentheses_EXTERNAL_OBJECTS =

20.Valid_Parentheses.exe: CMakeFiles/20.Valid_Parentheses.dir/code/5.stack_and_queue/20.Valid_Parentheses.cpp.obj
20.Valid_Parentheses.exe: CMakeFiles/20.Valid_Parentheses.dir/build.make
20.Valid_Parentheses.exe: CMakeFiles/20.Valid_Parentheses.dir/linklibs.rsp
20.Valid_Parentheses.exe: CMakeFiles/20.Valid_Parentheses.dir/objects1.rsp
20.Valid_Parentheses.exe: CMakeFiles/20.Valid_Parentheses.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\leetcode c++\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 20.Valid_Parentheses.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\20.Valid_Parentheses.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/20.Valid_Parentheses.dir/build: 20.Valid_Parentheses.exe

.PHONY : CMakeFiles/20.Valid_Parentheses.dir/build

CMakeFiles/20.Valid_Parentheses.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\20.Valid_Parentheses.dir\cmake_clean.cmake
.PHONY : CMakeFiles/20.Valid_Parentheses.dir/clean

CMakeFiles/20.Valid_Parentheses.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\leetcode c++" "E:\leetcode c++" "E:\leetcode c++\cmake-build-debug" "E:\leetcode c++\cmake-build-debug" "E:\leetcode c++\cmake-build-debug\CMakeFiles\20.Valid_Parentheses.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/20.Valid_Parentheses.dir/depend

