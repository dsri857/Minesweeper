# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = C:\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Hp\Desktop\testrun

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Hp\Desktop\testrun\build

# Include any dependencies generated for this target.
include CMakeFiles/nibbles.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/nibbles.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/nibbles.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nibbles.dir/flags.make

CMakeFiles/nibbles.dir/main.cpp.obj: CMakeFiles/nibbles.dir/flags.make
CMakeFiles/nibbles.dir/main.cpp.obj: CMakeFiles/nibbles.dir/includes_CXX.rsp
CMakeFiles/nibbles.dir/main.cpp.obj: C:/Users/Hp/Desktop/testrun/main.cpp
CMakeFiles/nibbles.dir/main.cpp.obj: CMakeFiles/nibbles.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Hp\Desktop\testrun\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/nibbles.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/nibbles.dir/main.cpp.obj -MF CMakeFiles\nibbles.dir\main.cpp.obj.d -o CMakeFiles\nibbles.dir\main.cpp.obj -c C:\Users\Hp\Desktop\testrun\main.cpp

CMakeFiles/nibbles.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nibbles.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Hp\Desktop\testrun\main.cpp > CMakeFiles\nibbles.dir\main.cpp.i

CMakeFiles/nibbles.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nibbles.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Hp\Desktop\testrun\main.cpp -o CMakeFiles\nibbles.dir\main.cpp.s

# Object files for target nibbles
nibbles_OBJECTS = \
"CMakeFiles/nibbles.dir/main.cpp.obj"

# External object files for target nibbles
nibbles_EXTERNAL_OBJECTS =

nibbles.exe: CMakeFiles/nibbles.dir/main.cpp.obj
nibbles.exe: CMakeFiles/nibbles.dir/build.make
nibbles.exe: C:/SFML/lib/libsfml-system-d.a
nibbles.exe: C:/SFML/lib/libsfml-window-d.a
nibbles.exe: C:/SFML/lib/libsfml-graphics-d.a
nibbles.exe: CMakeFiles/nibbles.dir/linkLibs.rsp
nibbles.exe: CMakeFiles/nibbles.dir/objects1.rsp
nibbles.exe: CMakeFiles/nibbles.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Hp\Desktop\testrun\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable nibbles.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\nibbles.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nibbles.dir/build: nibbles.exe
.PHONY : CMakeFiles/nibbles.dir/build

CMakeFiles/nibbles.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\nibbles.dir\cmake_clean.cmake
.PHONY : CMakeFiles/nibbles.dir/clean

CMakeFiles/nibbles.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Hp\Desktop\testrun C:\Users\Hp\Desktop\testrun C:\Users\Hp\Desktop\testrun\build C:\Users\Hp\Desktop\testrun\build C:\Users\Hp\Desktop\testrun\build\CMakeFiles\nibbles.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nibbles.dir/depend

