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
CMAKE_SOURCE_DIR = /home/abdel/loggerDaemon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abdel/loggerDaemon/build

# Include any dependencies generated for this target.
include CMakeFiles/app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app.dir/flags.make

CMakeFiles/app.dir/src/app.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/app.cpp.o: ../src/app.cpp
CMakeFiles/app.dir/src/app.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abdel/loggerDaemon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/app.dir/src/app.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/src/app.cpp.o -MF CMakeFiles/app.dir/src/app.cpp.o.d -o CMakeFiles/app.dir/src/app.cpp.o -c /home/abdel/loggerDaemon/src/app.cpp

CMakeFiles/app.dir/src/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/app.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abdel/loggerDaemon/src/app.cpp > CMakeFiles/app.dir/src/app.cpp.i

CMakeFiles/app.dir/src/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/app.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abdel/loggerDaemon/src/app.cpp -o CMakeFiles/app.dir/src/app.cpp.s

# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/src/app.cpp.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

app: CMakeFiles/app.dir/src/app.cpp.o
app: CMakeFiles/app.dir/build.make
app: /usr/local/lib/libboost_log_setup.so.1.83.0
app: /usr/local/lib/libboost_system.so.1.83.0
app: library/libipclib.a
app: library/liblogger.a
app: /usr/local/lib/libboost_log.so.1.83.0
app: /usr/local/lib/libboost_thread.so.1.83.0
app: /usr/local/lib/libboost_chrono.so.1.83.0
app: /usr/local/lib/libboost_filesystem.so.1.83.0
app: /usr/local/lib/libboost_atomic.so.1.83.0
app: /usr/local/lib/libboost_regex.so.1.83.0
app: CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/abdel/loggerDaemon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app.dir/build: app
.PHONY : CMakeFiles/app.dir/build

CMakeFiles/app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/app.dir/clean

CMakeFiles/app.dir/depend:
	cd /home/abdel/loggerDaemon/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abdel/loggerDaemon /home/abdel/loggerDaemon /home/abdel/loggerDaemon/build /home/abdel/loggerDaemon/build /home/abdel/loggerDaemon/build/CMakeFiles/app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/app.dir/depend

