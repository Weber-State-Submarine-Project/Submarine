// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from orientation_msg:msg/Esc.idl
// generated code does not contain a copyright notice
#include "orientation_msg/msg/detail/esc__rosidl_typesupport_fastrtps_cpp.hpp"
#include "orientation_msg/msg/detail/esc__functions.h"
#include "orientation_msg/msg/detail/esc__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace orientation_msg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_orientation_msg
cdr_serialize(
  const orientation_msg::msg::Esc & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: motor_selection
  cdr << ros_message.motor_selection;

  // Member: power_percentage
  cdr << ros_message.power_percentage;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_orientation_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  orientation_msg::msg::Esc & ros_message)
{
  // Member: motor_selection
  cdr >> ros_message.motor_selection;

  // Member: power_percentage
  cdr >> ros_message.power_percentage;

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_orientation_msg
get_serialized_size(
  const orientation_msg::msg::Esc & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: motor_selection
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.motor_selection.size() + 1);

  // Member: power_percentage
  {
    size_t item_size = sizeof(ros_message.power_percentage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_orientation_msg
max_serialized_size_Esc(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: motor_selection
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // Member: power_percentage
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = orientation_msg::msg::Esc;
    is_plain =
      (
      offsetof(DataType, power_percentage) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_orientation_msg
cdr_serialize_key(
  const orientation_msg::msg::Esc & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: motor_selection
  cdr << ros_message.motor_selection;

  // Member: power_percentage
  cdr << ros_message.power_percentage;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_orientation_msg
get_serialized_size_key(
  const orientation_msg::msg::Esc & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: motor_selection
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.motor_selection.size() + 1);

  // Member: power_percentage
  {
    size_t item_size = sizeof(ros_message.power_percentage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_orientation_msg
max_serialized_size_key_Esc(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: motor_selection
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: power_percentage
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = orientation_msg::msg::Esc;
    is_plain =
      (
      offsetof(DataType, power_percentage) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _Esc__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const orientation_msg::msg::Esc *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Esc__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<orientation_msg::msg::Esc *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Esc__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const orientation_msg::msg::Esc *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Esc__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Esc(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Esc__callbacks = {
  "orientation_msg::msg",
  "Esc",
  _Esc__cdr_serialize,
  _Esc__cdr_deserialize,
  _Esc__get_serialized_size,
  _Esc__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Esc__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Esc__callbacks,
  get_message_typesupport_handle_function,
  &orientation_msg__msg__Esc__get_type_hash,
  &orientation_msg__msg__Esc__get_type_description,
  &orientation_msg__msg__Esc__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace orientation_msg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_orientation_msg
const rosidl_message_type_support_t *
get_message_type_support_handle<orientation_msg::msg::Esc>()
{
  return &orientation_msg::msg::typesupport_fastrtps_cpp::_Esc__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, orientation_msg, msg, Esc)() {
  return &orientation_msg::msg::typesupport_fastrtps_cpp::_Esc__handle;
}

#ifdef __cplusplus
}
#endif
