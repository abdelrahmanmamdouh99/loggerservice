# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/abdel/clone/loggerservice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abdel/clone/loggerservice/build

# Include any dependencies generated for this target.
include library/CMakeFiles/ipclib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include library/CMakeFiles/ipclib.dir/compiler_depend.make

# Include the progress variables for this target.
include library/CMakeFiles/ipclib.dir/progress.make

# Include the compile flags for this target's objects.
include library/CMakeFiles/ipclib.dir/flags.make

library/CMakeFiles/ipclib.dir/IPCLib.cpp.o: library/CMakeFiles/ipclib.dir/flags.make
library/CMakeFiles/ipclib.dir/IPCLib.cpp.o: ../library/IPCLib.cpp
library/CMakeFiles/ipclib.dir/IPCLib.cpp.o: library/CMakeFiles/ipclib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abdel/clone/loggerservice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object library/CMakeFiles/ipclib.dir/IPCLib.cpp.o"
	cd /home/abdel/clone/loggerservice/build/library && /usr/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT library/CMakeFiles/ipclib.dir/IPCLib.cpp.o -MF CMakeFiles/ipclib.dir/IPCLib.cpp.o.d -o CMakeFiles/ipclib.dir/IPCLib.cpp.o -c /home/abdel/clone/loggerservice/library/IPCLib.cpp

library/CMakeFiles/ipclib.dir/IPCLib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ipclib.dir/IPCLib.cpp.i"
	cd /home/abdel/clone/loggerservice/build/library && /usr/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abdel/clone/loggerservice/library/IPCLib.cpp > CMakeFiles/ipclib.dir/IPCLib.cpp.i

library/CMakeFiles/ipclib.dir/IPCLib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ipclib.dir/IPCLib.cpp.s"
	cd /home/abdel/clone/loggerservice/build/library && /usr/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abdel/clone/loggerservice/library/IPCLib.cpp -o CMakeFiles/ipclib.dir/IPCLib.cpp.s

# Object files for target ipclib
ipclib_OBJECTS = \
"CMakeFiles/ipclib.dir/IPCLib.cpp.o"

# External object files for target ipclib
ipclib_EXTERNAL_OBJECTS =

library/libipclib.a: library/CMakeFiles/ipclib.dir/IPCLib.cpp.o
library/libipclib.a: library/CMakeFiles/ipclib.dir/build.make
library/libipclib.a: library/CMakeFiles/ipclib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/abdel/clone/loggerservice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libipclib.a"
	cd /home/abdel/clone/loggerservice/build/library && $(CMAKE_COMMAND) -P CMakeFiles/ipclib.dir/cmake_clean_target.cmake
	cd /home/abdel/clone/loggerservice/build/library && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ipclib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
library/CMakeFiles/ipclib.dir/build: library/libipclib.a
.PHONY : library/CMakeFiles/ipclib.dir/build

library/CMakeFiles/ipclib.dir/clean:
	cd /home/abdel/clone/loggerservice/build/library && $(CMAKE_COMMAND) -P CMakeFiles/ipclib.dir/cmake_clean.cmake
.PHONY : library/CMakeFiles/ipclib.dir/clean

library/CMakeFiles/ipclib.dir/depend:
	cd /home/abdel/clone/loggerservice/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abdel/clone/loggerservice /home/abdel/clone/loggerservice/library /home/abdel/clone/loggerservice/build /home/abdel/clone/loggerservice/build/library /home/abdel/clone/loggerservice/build/library/CMakeFiles/ipclib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : library/CMakeFiles/ipclib.dir/depend

