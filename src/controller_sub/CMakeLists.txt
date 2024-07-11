cmake_minimum_required(VERSION 3.5)
project(controller_sub)

# Find packages and libraries in ROS 2
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)

# Add executable
add_executable(controller_sub src/controller_sub.cpp)

# Include directories
target_include_directories(controller_sub
  PRIVATE
  include
  ${rclcpp_INCLUDE_DIRS}
  ${sensor_msgs_INCLUDE_DIRS}
)

# Link against libraries
ament_target_dependencies(controller_sub
  rclcpp
  sensor_msgs
)

# Install executable
install(TARGETS controller_sub
  DESTINATION lib/${PROJECT_NAME}
)


# Testing
#if(BUILD_TESTING)
#  find_package(ament_lint_auto REQUIRED)
#  ament_lint_auto_find_test_dependencies()
#endif()

# Install package.xml
install(FILES package.xml
  DESTINATION share/${PROJECT_NAME}
)

ament_package()

