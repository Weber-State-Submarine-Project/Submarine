cmake_minimum_required(VERSION 3.11.0 FATAL_ERROR)

project(Odometer)

find_package(gz-cmake3 REQUIRED)
find_package(gz-sensors8 REQUIRED)
set(GZ_SENSORS_VER ${gz-sensors8_VERSION_MAJOR})

add_library(${PROJECT_NAME} SHARED ${PROJECT_NAME}.cc)
target_link_libraries(${PROJECT_NAME}
  PUBLIC gz-sensors${GZ_SENSORS_VER}::gz-sensors${GZ_SENSORS_VER})

