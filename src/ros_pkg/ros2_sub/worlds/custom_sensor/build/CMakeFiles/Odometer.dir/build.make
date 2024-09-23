# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/submarine/ros_ws/src/ros_pkg/ros2_sub/worlds/custom_sensor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/submarine/ros_ws/src/ros_pkg/ros2_sub/worlds/custom_sensor/build

# Include any dependencies generated for this target.
include CMakeFiles/Odometer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Odometer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Odometer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Odometer.dir/flags.make

CMakeFiles/Odometer.dir/Odometer.cc.o: CMakeFiles/Odometer.dir/flags.make
CMakeFiles/Odometer.dir/Odometer.cc.o: /home/submarine/ros_ws/src/ros_pkg/ros2_sub/worlds/custom_sensor/Odometer.cc
CMakeFiles/Odometer.dir/Odometer.cc.o: CMakeFiles/Odometer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/submarine/ros_ws/src/ros_pkg/ros2_sub/worlds/custom_sensor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Odometer.dir/Odometer.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Odometer.dir/Odometer.cc.o -MF CMakeFiles/Odometer.dir/Odometer.cc.o.d -o CMakeFiles/Odometer.dir/Odometer.cc.o -c /home/submarine/ros_ws/src/ros_pkg/ros2_sub/worlds/custom_sensor/Odometer.cc

CMakeFiles/Odometer.dir/Odometer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Odometer.dir/Odometer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/submarine/ros_ws/src/ros_pkg/ros2_sub/worlds/custom_sensor/Odometer.cc > CMakeFiles/Odometer.dir/Odometer.cc.i

CMakeFiles/Odometer.dir/Odometer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Odometer.dir/Odometer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/submarine/ros_ws/src/ros_pkg/ros2_sub/worlds/custom_sensor/Odometer.cc -o CMakeFiles/Odometer.dir/Odometer.cc.s

# Object files for target Odometer
Odometer_OBJECTS = \
"CMakeFiles/Odometer.dir/Odometer.cc.o"

# External object files for target Odometer
Odometer_EXTERNAL_OBJECTS =

libOdometer.so: CMakeFiles/Odometer.dir/Odometer.cc.o
libOdometer.so: CMakeFiles/Odometer.dir/build.make
libOdometer.so: /opt/ros/jazzy/opt/gz_sensors_vendor/lib/libgz-sensors8.so.8.2.0
libOdometer.so: /opt/ros/jazzy/opt/gz_common_vendor/lib/libgz-common5.so.5.6.0
libOdometer.so: /opt/ros/jazzy/opt/gz_transport_vendor/lib/libgz-transport13.so.13.4.0
libOdometer.so: /usr/lib/aarch64-linux-gnu/libuuid.so
libOdometer.so: /usr/lib/aarch64-linux-gnu/libuuid.so
libOdometer.so: /opt/ros/jazzy/opt/sdformat_vendor/lib/libsdformat14.so.14.5.0
libOdometer.so: /opt/ros/jazzy/opt/gz_msgs_vendor/lib/libgz-msgs10.so.10.3.0
libOdometer.so: /opt/ros/jazzy/opt/gz_math_vendor/lib/libgz-math7.so.7.5.0
libOdometer.so: /opt/ros/jazzy/opt/gz_utils_vendor/lib/libgz-utils2.so.2.2.0
libOdometer.so: /usr/lib/aarch64-linux-gnu/libtinyxml2.so
libOdometer.so: /usr/lib/aarch64-linux-gnu/libtinyxml2.so
libOdometer.so: /usr/lib/aarch64-linux-gnu/libprotobuf.so
libOdometer.so: CMakeFiles/Odometer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/submarine/ros_ws/src/ros_pkg/ros2_sub/worlds/custom_sensor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libOdometer.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Odometer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Odometer.dir/build: libOdometer.so
.PHONY : CMakeFiles/Odometer.dir/build

CMakeFiles/Odometer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Odometer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Odometer.dir/clean

CMakeFiles/Odometer.dir/depend:
	cd /home/submarine/ros_ws/src/ros_pkg/ros2_sub/worlds/custom_sensor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/submarine/ros_ws/src/ros_pkg/ros2_sub/worlds/custom_sensor /home/submarine/ros_ws/src/ros_pkg/ros2_sub/worlds/custom_sensor /home/submarine/ros_ws/src/ros_pkg/ros2_sub/worlds/custom_sensor/build /home/submarine/ros_ws/src/ros_pkg/ros2_sub/worlds/custom_sensor/build /home/submarine/ros_ws/src/ros_pkg/ros2_sub/worlds/custom_sensor/build/CMakeFiles/Odometer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Odometer.dir/depend

