// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from orientation_msg:msg/Esc.idl
// generated code does not contain a copyright notice

#include "orientation_msg/msg/detail/esc__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_orientation_msg
const rosidl_type_hash_t *
orientation_msg__msg__Esc__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x37, 0x91, 0x06, 0x09, 0xfc, 0x92, 0x17, 0x47,
      0x14, 0x25, 0x40, 0xfc, 0x03, 0x9b, 0x89, 0x9a,
      0xb9, 0x27, 0xf0, 0xbe, 0xc5, 0x16, 0x2f, 0x4d,
      0x21, 0x70, 0xe2, 0x48, 0xa8, 0x77, 0xb2, 0x1d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char orientation_msg__msg__Esc__TYPE_NAME[] = "orientation_msg/msg/Esc";

// Define type names, field names, and default values
static char orientation_msg__msg__Esc__FIELD_NAME__motor_selection[] = "motor_selection";
static char orientation_msg__msg__Esc__FIELD_NAME__power_percentage[] = "power_percentage";

static rosidl_runtime_c__type_description__Field orientation_msg__msg__Esc__FIELDS[] = {
  {
    {orientation_msg__msg__Esc__FIELD_NAME__motor_selection, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orientation_msg__msg__Esc__FIELD_NAME__power_percentage, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
orientation_msg__msg__Esc__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {orientation_msg__msg__Esc__TYPE_NAME, 23, 23},
      {orientation_msg__msg__Esc__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# esc.msg is a custom msg for controlling both esc motors\n"
  "\n"
  "string motor_selection # Left or Right ESC\n"
  "int64 power_percentage  # Range from -100 to 100 (Negative: Reverse)";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
orientation_msg__msg__Esc__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {orientation_msg__msg__Esc__TYPE_NAME, 23, 23},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 171, 171},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
orientation_msg__msg__Esc__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *orientation_msg__msg__Esc__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
