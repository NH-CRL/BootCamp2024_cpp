# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = C:\Users\81809\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\81809\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\myClion\BootCamp2024_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\myClion\BootCamp2024_cpp\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Hello_world.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Hello_world.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Hello_world.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Hello_world.dir/flags.make

CMakeFiles/Hello_world.dir/Hello_world/HelloWorld.cpp.obj: CMakeFiles/Hello_world.dir/flags.make
CMakeFiles/Hello_world.dir/Hello_world/HelloWorld.cpp.obj: C:/myClion/BootCamp2024_cpp/Hello_world/HelloWorld.cpp
CMakeFiles/Hello_world.dir/Hello_world/HelloWorld.cpp.obj: CMakeFiles/Hello_world.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\myClion\BootCamp2024_cpp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Hello_world.dir/Hello_world/HelloWorld.cpp.obj"
	C:\Users\81809\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Hello_world.dir/Hello_world/HelloWorld.cpp.obj -MF CMakeFiles\Hello_world.dir\Hello_world\HelloWorld.cpp.obj.d -o CMakeFiles\Hello_world.dir\Hello_world\HelloWorld.cpp.obj -c C:\myClion\BootCamp2024_cpp\Hello_world\HelloWorld.cpp

CMakeFiles/Hello_world.dir/Hello_world/HelloWorld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Hello_world.dir/Hello_world/HelloWorld.cpp.i"
	C:\Users\81809\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\myClion\BootCamp2024_cpp\Hello_world\HelloWorld.cpp > CMakeFiles\Hello_world.dir\Hello_world\HelloWorld.cpp.i

CMakeFiles/Hello_world.dir/Hello_world/HelloWorld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Hello_world.dir/Hello_world/HelloWorld.cpp.s"
	C:\Users\81809\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\myClion\BootCamp2024_cpp\Hello_world\HelloWorld.cpp -o CMakeFiles\Hello_world.dir\Hello_world\HelloWorld.cpp.s

# Object files for target Hello_world
Hello_world_OBJECTS = \
"CMakeFiles/Hello_world.dir/Hello_world/HelloWorld.cpp.obj"

# External object files for target Hello_world
Hello_world_EXTERNAL_OBJECTS =

Hello_world.exe: CMakeFiles/Hello_world.dir/Hello_world/HelloWorld.cpp.obj
Hello_world.exe: CMakeFiles/Hello_world.dir/build.make
Hello_world.exe: CMakeFiles/Hello_world.dir/linkLibs.rsp
Hello_world.exe: CMakeFiles/Hello_world.dir/objects1.rsp
Hello_world.exe: CMakeFiles/Hello_world.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\myClion\BootCamp2024_cpp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Hello_world.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Hello_world.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Hello_world.dir/build: Hello_world.exe
.PHONY : CMakeFiles/Hello_world.dir/build

CMakeFiles/Hello_world.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Hello_world.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Hello_world.dir/clean

CMakeFiles/Hello_world.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\myClion\BootCamp2024_cpp C:\myClion\BootCamp2024_cpp C:\myClion\BootCamp2024_cpp\cmake-build-debug C:\myClion\BootCamp2024_cpp\cmake-build-debug C:\myClion\BootCamp2024_cpp\cmake-build-debug\CMakeFiles\Hello_world.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Hello_world.dir/depend

