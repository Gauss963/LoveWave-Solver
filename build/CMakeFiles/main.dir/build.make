# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/build"

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/codegen:
.PHONY : CMakeFiles/main.dir/codegen

CMakeFiles/main.dir/src/main.cc.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.cc.o: /Users/gausschang/Documents/University/Year5-2/Principles\ of\ Seismology/LoveWave/src/main.cc
CMakeFiles/main.dir/src/main.cc.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/src/main.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/main.cc.o -MF CMakeFiles/main.dir/src/main.cc.o.d -o CMakeFiles/main.dir/src/main.cc.o -c "/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/src/main.cc"

CMakeFiles/main.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/src/main.cc" > CMakeFiles/main.dir/src/main.cc.i

CMakeFiles/main.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/src/main.cc" -o CMakeFiles/main.dir/src/main.cc.s

CMakeFiles/main.dir/src/utils.cc.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/utils.cc.o: /Users/gausschang/Documents/University/Year5-2/Principles\ of\ Seismology/LoveWave/src/utils.cc
CMakeFiles/main.dir/src/utils.cc.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/utils.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/utils.cc.o -MF CMakeFiles/main.dir/src/utils.cc.o.d -o CMakeFiles/main.dir/src/utils.cc.o -c "/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/src/utils.cc"

CMakeFiles/main.dir/src/utils.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/utils.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/src/utils.cc" > CMakeFiles/main.dir/src/utils.cc.i

CMakeFiles/main.dir/src/utils.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/utils.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/src/utils.cc" -o CMakeFiles/main.dir/src/utils.cc.s

CMakeFiles/main.dir/src/LoveWave.cc.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/LoveWave.cc.o: /Users/gausschang/Documents/University/Year5-2/Principles\ of\ Seismology/LoveWave/src/LoveWave.cc
CMakeFiles/main.dir/src/LoveWave.cc.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/LoveWave.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/LoveWave.cc.o -MF CMakeFiles/main.dir/src/LoveWave.cc.o.d -o CMakeFiles/main.dir/src/LoveWave.cc.o -c "/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/src/LoveWave.cc"

CMakeFiles/main.dir/src/LoveWave.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/LoveWave.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/src/LoveWave.cc" > CMakeFiles/main.dir/src/LoveWave.cc.i

CMakeFiles/main.dir/src/LoveWave.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/LoveWave.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/src/LoveWave.cc" -o CMakeFiles/main.dir/src/LoveWave.cc.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/main.cc.o" \
"CMakeFiles/main.dir/src/utils.cc.o" \
"CMakeFiles/main.dir/src/LoveWave.cc.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/src/main.cc.o
main: CMakeFiles/main.dir/src/utils.cc.o
main: CMakeFiles/main.dir/src/LoveWave.cc.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd "/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave" "/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave" "/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/build" "/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/build" "/Users/gausschang/Documents/University/Year5-2/Principles of Seismology/LoveWave/build/CMakeFiles/main.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/main.dir/depend

