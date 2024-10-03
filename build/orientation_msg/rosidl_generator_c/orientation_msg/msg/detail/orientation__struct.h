// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from orientation_msg:msg/Orientation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orientation_msg/msg/orientation.h"


#ifndef ORIENTATION_MSG__MSG__DETAIL__ORIENTATION__STRUCT_H_
#define ORIENTATION_MSG__MSG__DETAIL__ORIENTATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/Orientation in the package orientation_msg.
/**
  * Orientation.msg
 */
typedef struct orientation_msg__msg__Orientation
{
  /// Acceleration m/s^2
  double acc_x;
  double acc_y;
  double acc_z;
  /// Gyro
  double gyro_x;
  double gyro_y;
  double gyro_z;
  /// Magnetometer
  double mag_x;
  double mag_y;
  double mag_z;
  /// Linear Acceleration
  double lin_acc_x;
  double lin_acc_y;
  double lin_acc_z;
  /// Quaternion for orientation
  double quat_x;
  double quat_y;
  double quat_z;
  double quat_w;
} orientation_msg__msg__Orientation;

// Struct for a sequence of orientation_msg__msg__Orientation.
typedef struct orientation_msg__msg__Orientation__Sequence
{
  orientation_msg__msg__Orientation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} orientation_msg__msg__Orientation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ORIENTATION_MSG__MSG__DETAIL__ORIENTATION__STRUCT_H_
