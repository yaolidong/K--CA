# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/K--CA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/K--CA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/K--CA.dir/flags.make

CMakeFiles/K--CA.dir/Blockchain.cpp.o: CMakeFiles/K--CA.dir/flags.make
CMakeFiles/K--CA.dir/Blockchain.cpp.o: ../Blockchain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/K--CA.dir/Blockchain.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/K--CA.dir/Blockchain.cpp.o -c /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/Blockchain.cpp

CMakeFiles/K--CA.dir/Blockchain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/K--CA.dir/Blockchain.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/Blockchain.cpp > CMakeFiles/K--CA.dir/Blockchain.cpp.i

CMakeFiles/K--CA.dir/Blockchain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/K--CA.dir/Blockchain.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/Blockchain.cpp -o CMakeFiles/K--CA.dir/Blockchain.cpp.s

CMakeFiles/K--CA.dir/Block.cpp.o: CMakeFiles/K--CA.dir/flags.make
CMakeFiles/K--CA.dir/Block.cpp.o: ../Block.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/K--CA.dir/Block.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/K--CA.dir/Block.cpp.o -c /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/Block.cpp

CMakeFiles/K--CA.dir/Block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/K--CA.dir/Block.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/Block.cpp > CMakeFiles/K--CA.dir/Block.cpp.i

CMakeFiles/K--CA.dir/Block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/K--CA.dir/Block.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/Block.cpp -o CMakeFiles/K--CA.dir/Block.cpp.s

CMakeFiles/K--CA.dir/main.cpp.o: CMakeFiles/K--CA.dir/flags.make
CMakeFiles/K--CA.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/K--CA.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/K--CA.dir/main.cpp.o -c /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/main.cpp

CMakeFiles/K--CA.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/K--CA.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/main.cpp > CMakeFiles/K--CA.dir/main.cpp.i

CMakeFiles/K--CA.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/K--CA.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/main.cpp -o CMakeFiles/K--CA.dir/main.cpp.s

CMakeFiles/K--CA.dir/sha256.cpp.o: CMakeFiles/K--CA.dir/flags.make
CMakeFiles/K--CA.dir/sha256.cpp.o: ../sha256.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/K--CA.dir/sha256.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/K--CA.dir/sha256.cpp.o -c /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/sha256.cpp

CMakeFiles/K--CA.dir/sha256.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/K--CA.dir/sha256.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/sha256.cpp > CMakeFiles/K--CA.dir/sha256.cpp.i

CMakeFiles/K--CA.dir/sha256.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/K--CA.dir/sha256.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/sha256.cpp -o CMakeFiles/K--CA.dir/sha256.cpp.s

CMakeFiles/K--CA.dir/Translation.cpp.o: CMakeFiles/K--CA.dir/flags.make
CMakeFiles/K--CA.dir/Translation.cpp.o: ../Translation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/K--CA.dir/Translation.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/K--CA.dir/Translation.cpp.o -c /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/Translation.cpp

CMakeFiles/K--CA.dir/Translation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/K--CA.dir/Translation.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/Translation.cpp > CMakeFiles/K--CA.dir/Translation.cpp.i

CMakeFiles/K--CA.dir/Translation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/K--CA.dir/Translation.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/Translation.cpp -o CMakeFiles/K--CA.dir/Translation.cpp.s

CMakeFiles/K--CA.dir/Cache.cpp.o: CMakeFiles/K--CA.dir/flags.make
CMakeFiles/K--CA.dir/Cache.cpp.o: ../Cache.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/K--CA.dir/Cache.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/K--CA.dir/Cache.cpp.o -c /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/Cache.cpp

CMakeFiles/K--CA.dir/Cache.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/K--CA.dir/Cache.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/Cache.cpp > CMakeFiles/K--CA.dir/Cache.cpp.i

CMakeFiles/K--CA.dir/Cache.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/K--CA.dir/Cache.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/Cache.cpp -o CMakeFiles/K--CA.dir/Cache.cpp.s

CMakeFiles/K--CA.dir/Sealer.cpp.o: CMakeFiles/K--CA.dir/flags.make
CMakeFiles/K--CA.dir/Sealer.cpp.o: ../Sealer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/K--CA.dir/Sealer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/K--CA.dir/Sealer.cpp.o -c /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/Sealer.cpp

CMakeFiles/K--CA.dir/Sealer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/K--CA.dir/Sealer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/Sealer.cpp > CMakeFiles/K--CA.dir/Sealer.cpp.i

CMakeFiles/K--CA.dir/Sealer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/K--CA.dir/Sealer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/Sealer.cpp -o CMakeFiles/K--CA.dir/Sealer.cpp.s

# Object files for target K--CA
K____CA_OBJECTS = \
"CMakeFiles/K--CA.dir/Blockchain.cpp.o" \
"CMakeFiles/K--CA.dir/Block.cpp.o" \
"CMakeFiles/K--CA.dir/main.cpp.o" \
"CMakeFiles/K--CA.dir/sha256.cpp.o" \
"CMakeFiles/K--CA.dir/Translation.cpp.o" \
"CMakeFiles/K--CA.dir/Cache.cpp.o" \
"CMakeFiles/K--CA.dir/Sealer.cpp.o"

# External object files for target K--CA
K____CA_EXTERNAL_OBJECTS =

K--CA: CMakeFiles/K--CA.dir/Blockchain.cpp.o
K--CA: CMakeFiles/K--CA.dir/Block.cpp.o
K--CA: CMakeFiles/K--CA.dir/main.cpp.o
K--CA: CMakeFiles/K--CA.dir/sha256.cpp.o
K--CA: CMakeFiles/K--CA.dir/Translation.cpp.o
K--CA: CMakeFiles/K--CA.dir/Cache.cpp.o
K--CA: CMakeFiles/K--CA.dir/Sealer.cpp.o
K--CA: CMakeFiles/K--CA.dir/build.make
K--CA: CMakeFiles/K--CA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable K--CA"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/K--CA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/K--CA.dir/build: K--CA

.PHONY : CMakeFiles/K--CA.dir/build

CMakeFiles/K--CA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/K--CA.dir/cmake_clean.cmake
.PHONY : CMakeFiles/K--CA.dir/clean

CMakeFiles/K--CA.dir/depend:
	cd /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/cmake-build-debug /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/cmake-build-debug /Users/yaolidong/Documents/GitHub/desktop-tutorial/K--CA/cmake-build-debug/CMakeFiles/K--CA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/K--CA.dir/depend
