# CMake generated Testfile for 
# Source directory: /home/submarine/gridmap_ws/src/grid_map/grid_map_costmap_2d/test
# Build directory: /home/submarine/gridmap_ws/build/grid_map_costmap_2d/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(grid_map_costmap_2d-test "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/submarine/gridmap_ws/build/grid_map_costmap_2d/test_results/grid_map_costmap_2d/grid_map_costmap_2d-test.gtest.xml" "--package-name" "grid_map_costmap_2d" "--output-file" "/home/submarine/gridmap_ws/build/grid_map_costmap_2d/ament_cmake_gtest/grid_map_costmap_2d-test.txt" "--command" "/home/submarine/gridmap_ws/build/grid_map_costmap_2d/test/grid_map_costmap_2d-test" "--gtest_output=xml:/home/submarine/gridmap_ws/build/grid_map_costmap_2d/test_results/grid_map_costmap_2d/grid_map_costmap_2d-test.gtest.xml")
set_tests_properties(grid_map_costmap_2d-test PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/submarine/gridmap_ws/build/grid_map_costmap_2d/test/grid_map_costmap_2d-test" TIMEOUT "60" WORKING_DIRECTORY "/home/submarine/gridmap_ws/build/grid_map_costmap_2d/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/submarine/gridmap_ws/src/grid_map/grid_map_costmap_2d/test/CMakeLists.txt;1;ament_add_gtest;/home/submarine/gridmap_ws/src/grid_map/grid_map_costmap_2d/test/CMakeLists.txt;0;")
add_test(costmap-2d-ros-test "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/submarine/gridmap_ws/build/grid_map_costmap_2d/test_results/grid_map_costmap_2d/costmap-2d-ros-test.gtest.xml" "--package-name" "grid_map_costmap_2d" "--output-file" "/home/submarine/gridmap_ws/build/grid_map_costmap_2d/ament_cmake_gtest/costmap-2d-ros-test.txt" "--command" "/home/submarine/gridmap_ws/build/grid_map_costmap_2d/test/costmap-2d-ros-test" "--gtest_output=xml:/home/submarine/gridmap_ws/build/grid_map_costmap_2d/test_results/grid_map_costmap_2d/costmap-2d-ros-test.gtest.xml")
set_tests_properties(costmap-2d-ros-test PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/submarine/gridmap_ws/build/grid_map_costmap_2d/test/costmap-2d-ros-test" TIMEOUT "60" WORKING_DIRECTORY "/home/submarine/gridmap_ws/build/grid_map_costmap_2d/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/submarine/gridmap_ws/src/grid_map/grid_map_costmap_2d/test/CMakeLists.txt;10;ament_add_gtest;/home/submarine/gridmap_ws/src/grid_map/grid_map_costmap_2d/test/CMakeLists.txt;0;")
subdirs("../gtest")
