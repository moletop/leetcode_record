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
include CMakeFiles/sword_to_offer_05_space_replace.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sword_to_offer_05_space_replace.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sword_to_offer_05_space_replace.dir/flags.make

CMakeFiles/sword_to_offer_05_space_replace.dir/code/4.string/sword_to_offer_05_space_replace.cpp.obj: CMakeFiles/sword_to_offer_05_space_replace.dir/flags.make
CMakeFiles/sword_to_offer_05_space_replace.dir/code/4.string/sword_to_offer_05_space_replace.cpp.obj: ../code/4.string/sword_to_offer_05_space_replace.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\leetcode c++\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sword_to_offer_05_space_replace.dir/code/4.string/sword_to_offer_05_space_replace.cpp.obj"
	"D:\Program Files (x86)\MinGw\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sword_to_offer_05_space_replace.dir\code\4.string\sword_to_offer_05_space_replace.cpp.obj -c "E:\leetcode c++\code\4.string\sword_to_offer_05_space_replace.cpp"

CMakeFiles/sword_to_offer_05_space_replace.dir/code/4.string/sword_to_offer_05_space_replace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sword_to_offer_05_space_replace.dir/code/4.string/sword_to_offer_05_space_replace.cpp.i"
	"D:\Program Files (x86)\MinGw\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\leetcode c++\code\4.string\sword_to_offer_05_space_replace.cpp" > CMakeFiles\sword_to_offer_05_space_replace.dir\code\4.string\sword_to_offer_05_space_replace.cpp.i

CMakeFiles/sword_to_offer_05_space_replace.dir/code/4.string/sword_to_offer_05_space_replace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sword_to_offer_05_space_replace.dir/code/4.string/sword_to_offer_05_space_replace.cpp.s"
	"D:\Program Files (x86)\MinGw\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\leetcode c++\code\4.string\sword_to_offer_05_space_replace.cpp" -o CMakeFiles\sword_to_offer_05_space_replace.dir\code\4.string\sword_to_offer_05_space_replace.cpp.s

# Object files for target sword_to_offer_05_space_replace
sword_to_offer_05_space_replace_OBJECTS = \
"CMakeFiles/sword_to_offer_05_space_replace.dir/code/4.string/sword_to_offer_05_space_replace.cpp.obj"

# External object files for target sword_to_offer_05_space_replace
sword_to_offer_05_space_replace_EXTERNAL_OBJECTS =

sword_to_offer_05_space_replace.exe: CMakeFiles/sword_to_offer_05_space_replace.dir/code/4.string/sword_to_offer_05_space_replace.cpp.obj
sword_to_offer_05_space_replace.exe: CMakeFiles/sword_to_offer_05_space_replace.dir/build.make
sword_to_offer_05_space_replace.exe: CMakeFiles/sword_to_offer_05_space_replace.dir/linklibs.rsp
sword_to_offer_05_space_replace.exe: CMakeFiles/sword_to_offer_05_space_replace.dir/objects1.rsp
sword_to_offer_05_space_replace.exe: CMakeFiles/sword_to_offer_05_space_replace.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\leetcode c++\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sword_to_offer_05_space_replace.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sword_to_offer_05_space_replace.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sword_to_offer_05_space_replace.dir/build: sword_to_offer_05_space_replace.exe

.PHONY : CMakeFiles/sword_to_offer_05_space_replace.dir/build

CMakeFiles/sword_to_offer_05_space_replace.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sword_to_offer_05_space_replace.dir\cmake_clean.cmake
.PHONY : CMakeFiles/sword_to_offer_05_space_replace.dir/clean

CMakeFiles/sword_to_offer_05_space_replace.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\leetcode c++" "E:\leetcode c++" "E:\leetcode c++\cmake-build-debug" "E:\leetcode c++\cmake-build-debug" "E:\leetcode c++\cmake-build-debug\CMakeFiles\sword_to_offer_05_space_replace.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/sword_to_offer_05_space_replace.dir/depend

