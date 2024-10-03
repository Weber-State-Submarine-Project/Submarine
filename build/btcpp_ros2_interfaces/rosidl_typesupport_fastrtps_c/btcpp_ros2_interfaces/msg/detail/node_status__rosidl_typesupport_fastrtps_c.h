// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from btcpp_ros2_interfaces:msg/NodeStatus.idl
// generated code does not contain a copyright notice
#ifndef BTCPP_ROS2_INTERFACES__MSG__DETAIL__NODE_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define BTCPP_ROS2_INTERFACES__MSG__DETAIL__NODE_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "btcpp_ros2_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "btcpp_ros2_interfaces/msg/detail/node_status__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_btcpp_ros2_interfaces
bool cdr_serialize_btcpp_ros2_interfaces__msg__NodeStatus(
  const btcpp_ros2_interfaces__msg__NodeStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_btcpp_ros2_interfaces
bool cdr_deserialize_btcpp_ros2_interfaces__msg__NodeStatus(
  eprosima::fastcdr::Cdr &,
  btcpp_ros2_interfaces__msg__NodeStatus * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_btcpp_ros2_interfaces
size_t get_serialized_size_btcpp_ros2_interfaces__msg__NodeStatus(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_btcpp_ros2_interfaces
size_t max_serialized_size_btcpp_ros2_interfaces__msg__NodeStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_btcpp_ros2_interfaces
bool cdr_serialize_key_btcpp_ros2_interfaces__msg__NodeStatus(
  const btcpp_ros2_interfaces__msg__NodeStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_btcpp_ros2_interfaces
size_t get_serialized_size_key_btcpp_ros2_interfaces__msg__NodeStatus(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_btcpp_ros2_interfaces
size_t max_serialized_size_key_btcpp_ros2_interfaces__msg__NodeStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_btcpp_ros2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, btcpp_ros2_interfaces, msg, NodeStatus)();

#ifdef __cplusplus
}
#endif

#endif  // BTCPP_ROS2_INTERFACES__MSG__DETAIL__NODE_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_