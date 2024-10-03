// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from orientation_msg:msg/Esc.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orientation_msg/msg/esc.h"


#ifndef ORIENTATION_MSG__MSG__DETAIL__ESC__STRUCT_H_
#define ORIENTATION_MSG__MSG__DETAIL__ESC__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'motor_selection'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Esc in the package orientation_msg.
/**
  * esc.msg is a custom msg for controlling both esc motors
 */
typedef struct orientation_msg__msg__Esc
{
  /// Left or Right ESC
  rosidl_runtime_c__String motor_selection;
  /// Range from -100 to 100 (Negative: Reverse)
  int64_t power_percentage;
} orientation_msg__msg__Esc;

// Struct for a sequence of orientation_msg__msg__Esc.
typedef struct orientation_msg__msg__Esc__Sequence
{
  orientation_msg__msg__Esc * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} orientation_msg__msg__Esc__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ORIENTATION_MSG__MSG__DETAIL__ESC__STRUCT_H_
