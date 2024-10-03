# CMake generated Testfile for 
# Source directory: /home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters
# Build directory: /home/submarine/ros_ws/build/pcl_ros/tests/filters
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_pcl_ros::ExtractIndices "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_pcl_ros::ExtractIndices.xunit.xml" "--package-name" "pcl_ros" "--output-file" "/home/submarine/ros_ws/build/pcl_ros/ament_cmake_pytest/test_pcl_ros::ExtractIndices.txt" "--env" "DUMMY_PLUGIN=pcl_ros_tests_filters::DummyTopics" "FILTER_PLUGIN=pcl_ros::ExtractIndices" "--append-env" "AMENT_PREFIX_PATH=/home/submarine/ros_ws/build/pcl_ros/tests/filters/test_ament_index" "--command" "/usr/bin/python3" "-u" "-m" "pytest" "/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/test_filter_component.py" "-o" "cache_dir=/home/submarine/ros_ws/build/pcl_ros/tests/filters/ament_cmake_pytest/test_pcl_ros::ExtractIndices/.cache" "--junit-xml=/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_pcl_ros::ExtractIndices.xunit.xml" "--junit-prefix=pcl_ros")
set_tests_properties(test_pcl_ros::ExtractIndices PROPERTIES  LABELS "pytest" TIMEOUT "60" WORKING_DIRECTORY "/home/submarine/ros_ws/build/pcl_ros/tests/filters" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_pytest/cmake/ament_add_pytest_test.cmake;177;ament_add_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;25;ament_add_pytest_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;0;")
add_test(test_pcl_ros::PassThrough "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_pcl_ros::PassThrough.xunit.xml" "--package-name" "pcl_ros" "--output-file" "/home/submarine/ros_ws/build/pcl_ros/ament_cmake_pytest/test_pcl_ros::PassThrough.txt" "--env" "DUMMY_PLUGIN=pcl_ros_tests_filters::DummyTopics" "FILTER_PLUGIN=pcl_ros::PassThrough" "--append-env" "AMENT_PREFIX_PATH=/home/submarine/ros_ws/build/pcl_ros/tests/filters/test_ament_index" "--command" "/usr/bin/python3" "-u" "-m" "pytest" "/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/test_filter_component.py" "-o" "cache_dir=/home/submarine/ros_ws/build/pcl_ros/tests/filters/ament_cmake_pytest/test_pcl_ros::PassThrough/.cache" "--junit-xml=/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_pcl_ros::PassThrough.xunit.xml" "--junit-prefix=pcl_ros")
set_tests_properties(test_pcl_ros::PassThrough PROPERTIES  LABELS "pytest" TIMEOUT "60" WORKING_DIRECTORY "/home/submarine/ros_ws/build/pcl_ros/tests/filters" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_pytest/cmake/ament_add_pytest_test.cmake;177;ament_add_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;31;ament_add_pytest_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;0;")
add_test(test_pcl_ros::ProjectInliers "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_pcl_ros::ProjectInliers.xunit.xml" "--package-name" "pcl_ros" "--output-file" "/home/submarine/ros_ws/build/pcl_ros/ament_cmake_pytest/test_pcl_ros::ProjectInliers.txt" "--env" "DUMMY_PLUGIN=pcl_ros_tests_filters::DummyTopics" "FILTER_PLUGIN=pcl_ros::ProjectInliers" "PARAMETERS={'model_type':0}" "--append-env" "AMENT_PREFIX_PATH=/home/submarine/ros_ws/build/pcl_ros/tests/filters/test_ament_index" "--command" "/usr/bin/python3" "-u" "-m" "pytest" "/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/test_filter_component.py" "-o" "cache_dir=/home/submarine/ros_ws/build/pcl_ros/tests/filters/ament_cmake_pytest/test_pcl_ros::ProjectInliers/.cache" "--junit-xml=/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_pcl_ros::ProjectInliers.xunit.xml" "--junit-prefix=pcl_ros")
set_tests_properties(test_pcl_ros::ProjectInliers PROPERTIES  LABELS "pytest" TIMEOUT "60" WORKING_DIRECTORY "/home/submarine/ros_ws/build/pcl_ros/tests/filters" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_pytest/cmake/ament_add_pytest_test.cmake;177;ament_add_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;37;ament_add_pytest_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;0;")
add_test(test_pcl_ros::RadiusOutlierRemoval "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_pcl_ros::RadiusOutlierRemoval.xunit.xml" "--package-name" "pcl_ros" "--output-file" "/home/submarine/ros_ws/build/pcl_ros/ament_cmake_pytest/test_pcl_ros::RadiusOutlierRemoval.txt" "--env" "DUMMY_PLUGIN=pcl_ros_tests_filters::DummyTopics" "FILTER_PLUGIN=pcl_ros::RadiusOutlierRemoval" "--append-env" "AMENT_PREFIX_PATH=/home/submarine/ros_ws/build/pcl_ros/tests/filters/test_ament_index" "--command" "/usr/bin/python3" "-u" "-m" "pytest" "/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/test_filter_component.py" "-o" "cache_dir=/home/submarine/ros_ws/build/pcl_ros/tests/filters/ament_cmake_pytest/test_pcl_ros::RadiusOutlierRemoval/.cache" "--junit-xml=/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_pcl_ros::RadiusOutlierRemoval.xunit.xml" "--junit-prefix=pcl_ros")
set_tests_properties(test_pcl_ros::RadiusOutlierRemoval PROPERTIES  LABELS "pytest" TIMEOUT "60" WORKING_DIRECTORY "/home/submarine/ros_ws/build/pcl_ros/tests/filters" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_pytest/cmake/ament_add_pytest_test.cmake;177;ament_add_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;44;ament_add_pytest_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;0;")
add_test(test_pcl_ros::StatisticalOutlierRemoval "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_pcl_ros::StatisticalOutlierRemoval.xunit.xml" "--package-name" "pcl_ros" "--output-file" "/home/submarine/ros_ws/build/pcl_ros/ament_cmake_pytest/test_pcl_ros::StatisticalOutlierRemoval.txt" "--env" "DUMMY_PLUGIN=pcl_ros_tests_filters::DummyTopics" "FILTER_PLUGIN=pcl_ros::StatisticalOutlierRemoval" "--append-env" "AMENT_PREFIX_PATH=/home/submarine/ros_ws/build/pcl_ros/tests/filters/test_ament_index" "--command" "/usr/bin/python3" "-u" "-m" "pytest" "/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/test_filter_component.py" "-o" "cache_dir=/home/submarine/ros_ws/build/pcl_ros/tests/filters/ament_cmake_pytest/test_pcl_ros::StatisticalOutlierRemoval/.cache" "--junit-xml=/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_pcl_ros::StatisticalOutlierRemoval.xunit.xml" "--junit-prefix=pcl_ros")
set_tests_properties(test_pcl_ros::StatisticalOutlierRemoval PROPERTIES  LABELS "pytest" TIMEOUT "60" WORKING_DIRECTORY "/home/submarine/ros_ws/build/pcl_ros/tests/filters" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_pytest/cmake/ament_add_pytest_test.cmake;177;ament_add_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;50;ament_add_pytest_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;0;")
add_test(test_pcl_ros::CropBox "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_pcl_ros::CropBox.xunit.xml" "--package-name" "pcl_ros" "--output-file" "/home/submarine/ros_ws/build/pcl_ros/ament_cmake_pytest/test_pcl_ros::CropBox.txt" "--env" "DUMMY_PLUGIN=pcl_ros_tests_filters::DummyTopics" "FILTER_PLUGIN=pcl_ros::CropBox" "--append-env" "AMENT_PREFIX_PATH=/home/submarine/ros_ws/build/pcl_ros/tests/filters/test_ament_index" "--command" "/usr/bin/python3" "-u" "-m" "pytest" "/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/test_filter_component.py" "-o" "cache_dir=/home/submarine/ros_ws/build/pcl_ros/tests/filters/ament_cmake_pytest/test_pcl_ros::CropBox/.cache" "--junit-xml=/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_pcl_ros::CropBox.xunit.xml" "--junit-prefix=pcl_ros")
set_tests_properties(test_pcl_ros::CropBox PROPERTIES  LABELS "pytest" TIMEOUT "60" WORKING_DIRECTORY "/home/submarine/ros_ws/build/pcl_ros/tests/filters" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_pytest/cmake/ament_add_pytest_test.cmake;177;ament_add_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;56;ament_add_pytest_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;0;")
add_test(test_pcl_ros::VoxelGrid "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_pcl_ros::VoxelGrid.xunit.xml" "--package-name" "pcl_ros" "--output-file" "/home/submarine/ros_ws/build/pcl_ros/ament_cmake_pytest/test_pcl_ros::VoxelGrid.txt" "--env" "DUMMY_PLUGIN=pcl_ros_tests_filters::DummyTopics" "FILTER_PLUGIN=pcl_ros::VoxelGrid" "--append-env" "AMENT_PREFIX_PATH=/home/submarine/ros_ws/build/pcl_ros/tests/filters/test_ament_index" "--command" "/usr/bin/python3" "-u" "-m" "pytest" "/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/test_filter_component.py" "-o" "cache_dir=/home/submarine/ros_ws/build/pcl_ros/tests/filters/ament_cmake_pytest/test_pcl_ros::VoxelGrid/.cache" "--junit-xml=/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_pcl_ros::VoxelGrid.xunit.xml" "--junit-prefix=pcl_ros")
set_tests_properties(test_pcl_ros::VoxelGrid PROPERTIES  LABELS "pytest" TIMEOUT "60" WORKING_DIRECTORY "/home/submarine/ros_ws/build/pcl_ros/tests/filters" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_pytest/cmake/ament_add_pytest_test.cmake;177;ament_add_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;62;ament_add_pytest_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;0;")
add_test(test_filter_extract_indices_node "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_filter_extract_indices_node.xunit.xml" "--package-name" "pcl_ros" "--output-file" "/home/submarine/ros_ws/build/pcl_ros/ament_cmake_pytest/test_filter_extract_indices_node.txt" "--env" "DUMMY_PLUGIN=pcl_ros_tests_filters::DummyTopics" "FILTER_EXECUTABLE=filter_extract_indices_node" "--append-env" "AMENT_PREFIX_PATH=/home/submarine/ros_ws/build/pcl_ros/tests/filters/test_ament_index" "--command" "/usr/bin/python3" "-u" "-m" "pytest" "/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/test_filter_executable.py" "-o" "cache_dir=/home/submarine/ros_ws/build/pcl_ros/tests/filters/ament_cmake_pytest/test_filter_extract_indices_node/.cache" "--junit-xml=/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_filter_extract_indices_node.xunit.xml" "--junit-prefix=pcl_ros")
set_tests_properties(test_filter_extract_indices_node PROPERTIES  LABELS "pytest" TIMEOUT "60" WORKING_DIRECTORY "/home/submarine/ros_ws/build/pcl_ros/tests/filters" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_pytest/cmake/ament_add_pytest_test.cmake;177;ament_add_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;70;ament_add_pytest_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;0;")
add_test(test_filter_passthrough_node "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_filter_passthrough_node.xunit.xml" "--package-name" "pcl_ros" "--output-file" "/home/submarine/ros_ws/build/pcl_ros/ament_cmake_pytest/test_filter_passthrough_node.txt" "--env" "DUMMY_PLUGIN=pcl_ros_tests_filters::DummyTopics" "FILTER_EXECUTABLE=filter_passthrough_node" "--append-env" "AMENT_PREFIX_PATH=/home/submarine/ros_ws/build/pcl_ros/tests/filters/test_ament_index" "--command" "/usr/bin/python3" "-u" "-m" "pytest" "/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/test_filter_executable.py" "-o" "cache_dir=/home/submarine/ros_ws/build/pcl_ros/tests/filters/ament_cmake_pytest/test_filter_passthrough_node/.cache" "--junit-xml=/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_filter_passthrough_node.xunit.xml" "--junit-prefix=pcl_ros")
set_tests_properties(test_filter_passthrough_node PROPERTIES  LABELS "pytest" TIMEOUT "60" WORKING_DIRECTORY "/home/submarine/ros_ws/build/pcl_ros/tests/filters" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_pytest/cmake/ament_add_pytest_test.cmake;177;ament_add_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;76;ament_add_pytest_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;0;")
add_test(test_filter_project_inliers_node "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_filter_project_inliers_node.xunit.xml" "--package-name" "pcl_ros" "--output-file" "/home/submarine/ros_ws/build/pcl_ros/ament_cmake_pytest/test_filter_project_inliers_node.txt" "--env" "DUMMY_PLUGIN=pcl_ros_tests_filters::DummyTopics" "FILTER_EXECUTABLE=filter_project_inliers_node" "PARAMETERS={'model_type':0}" "--append-env" "AMENT_PREFIX_PATH=/home/submarine/ros_ws/build/pcl_ros/tests/filters/test_ament_index" "--command" "/usr/bin/python3" "-u" "-m" "pytest" "/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/test_filter_executable.py" "-o" "cache_dir=/home/submarine/ros_ws/build/pcl_ros/tests/filters/ament_cmake_pytest/test_filter_project_inliers_node/.cache" "--junit-xml=/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_filter_project_inliers_node.xunit.xml" "--junit-prefix=pcl_ros")
set_tests_properties(test_filter_project_inliers_node PROPERTIES  LABELS "pytest" TIMEOUT "60" WORKING_DIRECTORY "/home/submarine/ros_ws/build/pcl_ros/tests/filters" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_pytest/cmake/ament_add_pytest_test.cmake;177;ament_add_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;82;ament_add_pytest_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;0;")
add_test(test_filter_radius_outlier_removal_node "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_filter_radius_outlier_removal_node.xunit.xml" "--package-name" "pcl_ros" "--output-file" "/home/submarine/ros_ws/build/pcl_ros/ament_cmake_pytest/test_filter_radius_outlier_removal_node.txt" "--env" "DUMMY_PLUGIN=pcl_ros_tests_filters::DummyTopics" "FILTER_EXECUTABLE=filter_radius_outlier_removal_node" "--append-env" "AMENT_PREFIX_PATH=/home/submarine/ros_ws/build/pcl_ros/tests/filters/test_ament_index" "--command" "/usr/bin/python3" "-u" "-m" "pytest" "/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/test_filter_executable.py" "-o" "cache_dir=/home/submarine/ros_ws/build/pcl_ros/tests/filters/ament_cmake_pytest/test_filter_radius_outlier_removal_node/.cache" "--junit-xml=/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_filter_radius_outlier_removal_node.xunit.xml" "--junit-prefix=pcl_ros")
set_tests_properties(test_filter_radius_outlier_removal_node PROPERTIES  LABELS "pytest" TIMEOUT "60" WORKING_DIRECTORY "/home/submarine/ros_ws/build/pcl_ros/tests/filters" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_pytest/cmake/ament_add_pytest_test.cmake;177;ament_add_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;89;ament_add_pytest_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;0;")
add_test(test_filter_statistical_outlier_removal_node "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_filter_statistical_outlier_removal_node.xunit.xml" "--package-name" "pcl_ros" "--output-file" "/home/submarine/ros_ws/build/pcl_ros/ament_cmake_pytest/test_filter_statistical_outlier_removal_node.txt" "--env" "DUMMY_PLUGIN=pcl_ros_tests_filters::DummyTopics" "FILTER_EXECUTABLE=filter_statistical_outlier_removal_node" "--append-env" "AMENT_PREFIX_PATH=/home/submarine/ros_ws/build/pcl_ros/tests/filters/test_ament_index" "--command" "/usr/bin/python3" "-u" "-m" "pytest" "/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/test_filter_executable.py" "-o" "cache_dir=/home/submarine/ros_ws/build/pcl_ros/tests/filters/ament_cmake_pytest/test_filter_statistical_outlier_removal_node/.cache" "--junit-xml=/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_filter_statistical_outlier_removal_node.xunit.xml" "--junit-prefix=pcl_ros")
set_tests_properties(test_filter_statistical_outlier_removal_node PROPERTIES  LABELS "pytest" TIMEOUT "60" WORKING_DIRECTORY "/home/submarine/ros_ws/build/pcl_ros/tests/filters" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_pytest/cmake/ament_add_pytest_test.cmake;177;ament_add_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;95;ament_add_pytest_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;0;")
add_test(test_filter_crop_box_node "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_filter_crop_box_node.xunit.xml" "--package-name" "pcl_ros" "--output-file" "/home/submarine/ros_ws/build/pcl_ros/ament_cmake_pytest/test_filter_crop_box_node.txt" "--env" "DUMMY_PLUGIN=pcl_ros_tests_filters::DummyTopics" "FILTER_EXECUTABLE=filter_crop_box_node" "--append-env" "AMENT_PREFIX_PATH=/home/submarine/ros_ws/build/pcl_ros/tests/filters/test_ament_index" "--command" "/usr/bin/python3" "-u" "-m" "pytest" "/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/test_filter_executable.py" "-o" "cache_dir=/home/submarine/ros_ws/build/pcl_ros/tests/filters/ament_cmake_pytest/test_filter_crop_box_node/.cache" "--junit-xml=/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_filter_crop_box_node.xunit.xml" "--junit-prefix=pcl_ros")
set_tests_properties(test_filter_crop_box_node PROPERTIES  LABELS "pytest" TIMEOUT "60" WORKING_DIRECTORY "/home/submarine/ros_ws/build/pcl_ros/tests/filters" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_pytest/cmake/ament_add_pytest_test.cmake;177;ament_add_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;101;ament_add_pytest_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;0;")
add_test(test_filter_voxel_grid_node "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_filter_voxel_grid_node.xunit.xml" "--package-name" "pcl_ros" "--output-file" "/home/submarine/ros_ws/build/pcl_ros/ament_cmake_pytest/test_filter_voxel_grid_node.txt" "--env" "DUMMY_PLUGIN=pcl_ros_tests_filters::DummyTopics" "FILTER_EXECUTABLE=filter_voxel_grid_node" "--append-env" "AMENT_PREFIX_PATH=/home/submarine/ros_ws/build/pcl_ros/tests/filters/test_ament_index" "--command" "/usr/bin/python3" "-u" "-m" "pytest" "/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/test_filter_executable.py" "-o" "cache_dir=/home/submarine/ros_ws/build/pcl_ros/tests/filters/ament_cmake_pytest/test_filter_voxel_grid_node/.cache" "--junit-xml=/home/submarine/ros_ws/build/pcl_ros/test_results/pcl_ros/test_filter_voxel_grid_node.xunit.xml" "--junit-prefix=pcl_ros")
set_tests_properties(test_filter_voxel_grid_node PROPERTIES  LABELS "pytest" TIMEOUT "60" WORKING_DIRECTORY "/home/submarine/ros_ws/build/pcl_ros/tests/filters" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_pytest/cmake/ament_add_pytest_test.cmake;177;ament_add_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;107;ament_add_pytest_test;/home/submarine/ros_ws/src/perception_pcl/pcl_ros/tests/filters/CMakeLists.txt;0;")
