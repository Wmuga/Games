# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Programming\JetBrains\CLion\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\Programming\JetBrains\CLion\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Documents\GitHub\Games\Game_Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Documents\GitHub\Games\Game_Engine\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Game_Engine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Game_Engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Game_Engine.dir/flags.make

CMakeFiles/Game_Engine.dir/main.cpp.obj: CMakeFiles/Game_Engine.dir/flags.make
CMakeFiles/Game_Engine.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\GitHub\Games\Game_Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Game_Engine.dir/main.cpp.obj"
	D:\Mingw\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Game_Engine.dir\main.cpp.obj -c D:\Documents\GitHub\Games\Game_Engine\main.cpp

CMakeFiles/Game_Engine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game_Engine.dir/main.cpp.i"
	D:\Mingw\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\GitHub\Games\Game_Engine\main.cpp > CMakeFiles\Game_Engine.dir\main.cpp.i

CMakeFiles/Game_Engine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game_Engine.dir/main.cpp.s"
	D:\Mingw\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\GitHub\Games\Game_Engine\main.cpp -o CMakeFiles\Game_Engine.dir\main.cpp.s

# Object files for target Game_Engine
Game_Engine_OBJECTS = \
"CMakeFiles/Game_Engine.dir/main.cpp.obj"

# External object files for target Game_Engine
Game_Engine_EXTERNAL_OBJECTS =

Game_Engine.exe: CMakeFiles/Game_Engine.dir/main.cpp.obj
Game_Engine.exe: CMakeFiles/Game_Engine.dir/build.make
Game_Engine.exe: CMakeFiles/Game_Engine.dir/linklibs.rsp
Game_Engine.exe: CMakeFiles/Game_Engine.dir/objects1.rsp
Game_Engine.exe: CMakeFiles/Game_Engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Documents\GitHub\Games\Game_Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Game_Engine.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Game_Engine.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Game_Engine.dir/build: Game_Engine.exe

.PHONY : CMakeFiles/Game_Engine.dir/build

CMakeFiles/Game_Engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Game_Engine.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Game_Engine.dir/clean

CMakeFiles/Game_Engine.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documents\GitHub\Games\Game_Engine D:\Documents\GitHub\Games\Game_Engine D:\Documents\GitHub\Games\Game_Engine\cmake-build-debug D:\Documents\GitHub\Games\Game_Engine\cmake-build-debug D:\Documents\GitHub\Games\Game_Engine\cmake-build-debug\CMakeFiles\Game_Engine.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Game_Engine.dir/depend

