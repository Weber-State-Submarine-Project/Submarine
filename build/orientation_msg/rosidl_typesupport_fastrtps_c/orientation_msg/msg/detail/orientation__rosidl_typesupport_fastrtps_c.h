// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from orientation_msg:msg/Orientation.idl
// generated code does not contain a copyright notice
#ifndef ORIENTATION_MSG__MSG__DETAIL__ORIENTATION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ORIENTATION_MSG__MSG__DETAIL__ORIENTATION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "orientation_msg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "orientation_msg/msg/detail/orientation__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orientation_msg
bool cdr_serialize_orientation_msg__msg__Orientation(
  const orientation_msg__msg__Orientation * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orientation_msg
bool cdr_deserialize_orientation_msg__msg__Orientation(
  eprosima::fastcdr::Cdr &,
  orientation_msg__msg__Orientation * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orientation_msg
size_t get_serialized_size_orientation_msg__msg__Orientation(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orientation_msg
size_t max_serialized_size_orientation_msg__msg__Orientation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orientation_msg
bool cdr_serialize_key_orientation_msg__msg__Orientation(
  const orientation_msg__msg__Orientation * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orientation_msg
size_t get_serialized_size_key_orientation_msg__msg__Orientation(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orientation_msg
size_t max_serialized_size_key_orientation_msg__msg__Orientation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orientation_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, orientation_msg, msg, Orientation)();

#ifdef __cplusplus
}
#endif

#endif  // ORIENTATION_MSG__MSG__DETAIL__ORIENTATION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
