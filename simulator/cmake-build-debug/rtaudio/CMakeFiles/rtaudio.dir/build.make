# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\ctag-tbd\simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\ctag-tbd\simulator\cmake-build-debug

# Include any dependencies generated for this target.
include rtaudio/CMakeFiles/rtaudio.dir/depend.make

# Include the progress variables for this target.
include rtaudio/CMakeFiles/rtaudio.dir/progress.make

# Include the compile flags for this target's objects.
include rtaudio/CMakeFiles/rtaudio.dir/flags.make

rtaudio/CMakeFiles/rtaudio.dir/RtAudio.cpp.obj: rtaudio/CMakeFiles/rtaudio.dir/flags.make
rtaudio/CMakeFiles/rtaudio.dir/RtAudio.cpp.obj: rtaudio/CMakeFiles/rtaudio.dir/includes_CXX.rsp
rtaudio/CMakeFiles/rtaudio.dir/RtAudio.cpp.obj: ../rtaudio/RtAudio.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\ctag-tbd\simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object rtaudio/CMakeFiles/rtaudio.dir/RtAudio.cpp.obj"
	cd /d C:\ctag-tbd\simulator\cmake-build-debug\rtaudio && C:\MinGW\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\rtaudio.dir\RtAudio.cpp.obj -c C:\ctag-tbd\simulator\rtaudio\RtAudio.cpp

rtaudio/CMakeFiles/rtaudio.dir/RtAudio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rtaudio.dir/RtAudio.cpp.i"
	cd /d C:\ctag-tbd\simulator\cmake-build-debug\rtaudio && C:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\ctag-tbd\simulator\rtaudio\RtAudio.cpp > CMakeFiles\rtaudio.dir\RtAudio.cpp.i

rtaudio/CMakeFiles/rtaudio.dir/RtAudio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rtaudio.dir/RtAudio.cpp.s"
	cd /d C:\ctag-tbd\simulator\cmake-build-debug\rtaudio && C:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\ctag-tbd\simulator\rtaudio\RtAudio.cpp -o CMakeFiles\rtaudio.dir\RtAudio.cpp.s

rtaudio/CMakeFiles/rtaudio.dir/rtaudio_c.cpp.obj: rtaudio/CMakeFiles/rtaudio.dir/flags.make
rtaudio/CMakeFiles/rtaudio.dir/rtaudio_c.cpp.obj: rtaudio/CMakeFiles/rtaudio.dir/includes_CXX.rsp
rtaudio/CMakeFiles/rtaudio.dir/rtaudio_c.cpp.obj: ../rtaudio/rtaudio_c.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\ctag-tbd\simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object rtaudio/CMakeFiles/rtaudio.dir/rtaudio_c.cpp.obj"
	cd /d C:\ctag-tbd\simulator\cmake-build-debug\rtaudio && C:\MinGW\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\rtaudio.dir\rtaudio_c.cpp.obj -c C:\ctag-tbd\simulator\rtaudio\rtaudio_c.cpp

rtaudio/CMakeFiles/rtaudio.dir/rtaudio_c.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rtaudio.dir/rtaudio_c.cpp.i"
	cd /d C:\ctag-tbd\simulator\cmake-build-debug\rtaudio && C:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\ctag-tbd\simulator\rtaudio\rtaudio_c.cpp > CMakeFiles\rtaudio.dir\rtaudio_c.cpp.i

rtaudio/CMakeFiles/rtaudio.dir/rtaudio_c.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rtaudio.dir/rtaudio_c.cpp.s"
	cd /d C:\ctag-tbd\simulator\cmake-build-debug\rtaudio && C:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\ctag-tbd\simulator\rtaudio\rtaudio_c.cpp -o CMakeFiles\rtaudio.dir\rtaudio_c.cpp.s

# Object files for target rtaudio
rtaudio_OBJECTS = \
"CMakeFiles/rtaudio.dir/RtAudio.cpp.obj" \
"CMakeFiles/rtaudio.dir/rtaudio_c.cpp.obj"

# External object files for target rtaudio
rtaudio_EXTERNAL_OBJECTS =

rtaudio/librtaudiod.a: rtaudio/CMakeFiles/rtaudio.dir/RtAudio.cpp.obj
rtaudio/librtaudiod.a: rtaudio/CMakeFiles/rtaudio.dir/rtaudio_c.cpp.obj
rtaudio/librtaudiod.a: rtaudio/CMakeFiles/rtaudio.dir/build.make
rtaudio/librtaudiod.a: rtaudio/CMakeFiles/rtaudio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\ctag-tbd\simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library librtaudiod.a"
	cd /d C:\ctag-tbd\simulator\cmake-build-debug\rtaudio && $(CMAKE_COMMAND) -P CMakeFiles\rtaudio.dir\cmake_clean_target.cmake
	cd /d C:\ctag-tbd\simulator\cmake-build-debug\rtaudio && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\rtaudio.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
rtaudio/CMakeFiles/rtaudio.dir/build: rtaudio/librtaudiod.a

.PHONY : rtaudio/CMakeFiles/rtaudio.dir/build

rtaudio/CMakeFiles/rtaudio.dir/clean:
	cd /d C:\ctag-tbd\simulator\cmake-build-debug\rtaudio && $(CMAKE_COMMAND) -P CMakeFiles\rtaudio.dir\cmake_clean.cmake
.PHONY : rtaudio/CMakeFiles/rtaudio.dir/clean

rtaudio/CMakeFiles/rtaudio.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\ctag-tbd\simulator C:\ctag-tbd\simulator\rtaudio C:\ctag-tbd\simulator\cmake-build-debug C:\ctag-tbd\simulator\cmake-build-debug\rtaudio C:\ctag-tbd\simulator\cmake-build-debug\rtaudio\CMakeFiles\rtaudio.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : rtaudio/CMakeFiles/rtaudio.dir/depend
