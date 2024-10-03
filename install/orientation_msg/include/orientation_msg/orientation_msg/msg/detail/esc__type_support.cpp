// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from orientation_msg:msg/Esc.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "orientation_msg/msg/detail/esc__functions.h"
#include "orientation_msg/msg/detail/esc__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace orientation_msg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Esc_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) orientation_msg::msg::Esc(_init);
}

void Esc_fini_function(void * message_memory)
{
  auto typed_message = static_cast<orientation_msg::msg::Esc *>(message_memory);
  typed_message->~Esc();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Esc_message_member_array[2] = {
  {
    "motor_selection",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(orientation_msg::msg::Esc, motor_selection),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "power_percentage",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(orientation_msg::msg::Esc, power_percentage),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Esc_message_members = {
  "orientation_msg::msg",  // message namespace
  "Esc",  // message name
  2,  // number of fields
  sizeof(orientation_msg::msg::Esc),
  false,  // has_any_key_member_
  Esc_message_member_array,  // message members
  Esc_init_function,  // function to initialize message memory (memory has to be allocated)
  Esc_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Esc_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Esc_message_members,
  get_message_typesupport_handle_function,
  &orientation_msg__msg__Esc__get_type_hash,
  &orientation_msg__msg__Esc__get_type_description,
  &orientation_msg__msg__Esc__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace orientation_msg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<orientation_msg::msg::Esc>()
{
  return &::orientation_msg::msg::rosidl_typesupport_introspection_cpp::Esc_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, orientation_msg, msg, Esc)() {
  return &::orientation_msg::msg::rosidl_typesupport_introspection_cpp::Esc_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
