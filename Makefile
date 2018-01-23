# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/michal/Sleeping-Barber-Problem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/michal/Sleeping-Barber-Problem

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/michal/Sleeping-Barber-Problem/CMakeFiles /home/michal/Sleeping-Barber-Problem/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/michal/Sleeping-Barber-Problem/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named barber

# Build rule for target.
barber: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 barber
.PHONY : barber

# fast build rule for target.
barber/fast:
	$(MAKE) -f CMakeFiles/barber.dir/build.make CMakeFiles/barber.dir/build
.PHONY : barber/fast

#=============================================================================
# Target rules for targets named client

# Build rule for target.
client: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 client
.PHONY : client

# fast build rule for target.
client/fast:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/build
.PHONY : client/fast

Queue.o: Queue.c.o

.PHONY : Queue.o

# target to build an object file
Queue.c.o:
	$(MAKE) -f CMakeFiles/barber.dir/build.make CMakeFiles/barber.dir/Queue.c.o
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Queue.c.o
.PHONY : Queue.c.o

Queue.i: Queue.c.i

.PHONY : Queue.i

# target to preprocess a source file
Queue.c.i:
	$(MAKE) -f CMakeFiles/barber.dir/build.make CMakeFiles/barber.dir/Queue.c.i
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Queue.c.i
.PHONY : Queue.c.i

Queue.s: Queue.c.s

.PHONY : Queue.s

# target to generate assembly for a file
Queue.c.s:
	$(MAKE) -f CMakeFiles/barber.dir/build.make CMakeFiles/barber.dir/Queue.c.s
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Queue.c.s
.PHONY : Queue.c.s

barber.o: barber.c.o

.PHONY : barber.o

# target to build an object file
barber.c.o:
	$(MAKE) -f CMakeFiles/barber.dir/build.make CMakeFiles/barber.dir/barber.c.o
.PHONY : barber.c.o

barber.i: barber.c.i

.PHONY : barber.i

# target to preprocess a source file
barber.c.i:
	$(MAKE) -f CMakeFiles/barber.dir/build.make CMakeFiles/barber.dir/barber.c.i
.PHONY : barber.c.i

barber.s: barber.c.s

.PHONY : barber.s

# target to generate assembly for a file
barber.c.s:
	$(MAKE) -f CMakeFiles/barber.dir/build.make CMakeFiles/barber.dir/barber.c.s
.PHONY : barber.c.s

client.o: client.c.o

.PHONY : client.o

# target to build an object file
client.c.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/client.c.o
.PHONY : client.c.o

client.i: client.c.i

.PHONY : client.i

# target to preprocess a source file
client.c.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/client.c.i
.PHONY : client.c.i

client.s: client.c.s

.PHONY : client.s

# target to generate assembly for a file
client.c.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/client.c.s
.PHONY : client.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... barber"
	@echo "... edit_cache"
	@echo "... client"
	@echo "... Queue.o"
	@echo "... Queue.i"
	@echo "... Queue.s"
	@echo "... barber.o"
	@echo "... barber.i"
	@echo "... barber.s"
	@echo "... client.o"
	@echo "... client.i"
	@echo "... client.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
