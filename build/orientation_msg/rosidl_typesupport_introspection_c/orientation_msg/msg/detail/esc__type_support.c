// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from orientation_msg:msg/Esc.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "orientation_msg/msg/detail/esc__rosidl_typesupport_introspection_c.h"
#include "orientation_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "orientation_msg/msg/detail/esc__functions.h"
#include "orientation_msg/msg/detail/esc__struct.h"


// Include directives for member types
// Member `motor_selection`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void orientation_msg__msg__Esc__rosidl_typesupport_introspection_c__Esc_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  orientation_msg__msg__Esc__init(message_memory);
}

void orientation_msg__msg__Esc__rosidl_typesupport_introspection_c__Esc_fini_function(void * message_memory)
{
  orientation_msg__msg__Esc__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember orientation_msg__msg__Esc__rosidl_typesupport_introspection_c__Esc_message_member_array[2] = {
  {
    "motor_selection",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(orientation_msg__msg__Esc, motor_selection),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "power_percentage",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(orientation_msg__msg__Esc, power_percentage),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers orientation_msg__msg__Esc__rosidl_typesupport_introspection_c__Esc_message_members = {
  "orientation_msg__msg",  // message namespace
  "Esc",  // message name
  2,  // number of fields
  sizeof(orientation_msg__msg__Esc),
  false,  // has_any_key_member_
  orientation_msg__msg__Esc__rosidl_typesupport_introspection_c__Esc_message_member_array,  // message members
  orientation_msg__msg__Esc__rosidl_typesupport_introspection_c__Esc_init_function,  // function to initialize message memory (memory has to be allocated)
  orientation_msg__msg__Esc__rosidl_typesupport_introspection_c__Esc_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t orientation_msg__msg__Esc__rosidl_typesupport_introspection_c__Esc_message_type_support_handle = {
  0,
  &orientation_msg__msg__Esc__rosidl_typesupport_introspection_c__Esc_message_members,
  get_message_typesupport_handle_function,
  &orientation_msg__msg__Esc__get_type_hash,
  &orientation_msg__msg__Esc__get_type_description,
  &orientation_msg__msg__Esc__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_orientation_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, orientation_msg, msg, Esc)() {
  if (!orientation_msg__msg__Esc__rosidl_typesupport_introspection_c__Esc_message_type_support_handle.typesupport_identifier) {
    orientation_msg__msg__Esc__rosidl_typesupport_introspection_c__Esc_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &orientation_msg__msg__Esc__rosidl_typesupport_introspection_c__Esc_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
