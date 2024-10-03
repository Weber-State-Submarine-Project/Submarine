// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from orientation_msg:msg/Orientation.idl
// generated code does not contain a copyright notice

#include "orientation_msg/msg/detail/orientation__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_orientation_msg
const rosidl_type_hash_t *
orientation_msg__msg__Orientation__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x81, 0xfa, 0xd5, 0x51, 0xb4, 0xa6, 0xb2, 0x80,
      0xbd, 0x8f, 0x29, 0xea, 0x42, 0xd0, 0xa4, 0xd7,
      0xe4, 0x4a, 0x23, 0x76, 0x98, 0x89, 0xcf, 0xa8,
      0x58, 0x09, 0x4b, 0x32, 0x40, 0x49, 0xa3, 0x34,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char orientation_msg__msg__Orientation__TYPE_NAME[] = "orientation_msg/msg/Orientation";

// Define type names, field names, and default values
static char orientation_msg__msg__Orientation__FIELD_NAME__acc_x[] = "acc_x";
static char orientation_msg__msg__Orientation__FIELD_NAME__acc_y[] = "acc_y";
static char orientation_msg__msg__Orientation__FIELD_NAME__acc_z[] = "acc_z";
static char orientation_msg__msg__Orientation__FIELD_NAME__gyro_x[] = "gyro_x";
static char orientation_msg__msg__Orientation__FIELD_NAME__gyro_y[] = "gyro_y";
static char orientation_msg__msg__Orientation__FIELD_NAME__gyro_z[] = "gyro_z";
static char orientation_msg__msg__Orientation__FIELD_NAME__mag_x[] = "mag_x";
static char orientation_msg__msg__Orientation__FIELD_NAME__mag_y[] = "mag_y";
static char orientation_msg__msg__Orientation__FIELD_NAME__mag_z[] = "mag_z";
static char orientation_msg__msg__Orientation__FIELD_NAME__lin_acc_x[] = "lin_acc_x";
static char orientation_msg__msg__Orientation__FIELD_NAME__lin_acc_y[] = "lin_acc_y";
static char orientation_msg__msg__Orientation__FIELD_NAME__lin_acc_z[] = "lin_acc_z";
static char orientation_msg__msg__Orientation__FIELD_NAME__quat_x[] = "quat_x";
static char orientation_msg__msg__Orientation__FIELD_NAME__quat_y[] = "quat_y";
static char orientation_msg__msg__Orientation__FIELD_NAME__quat_z[] = "quat_z";
static char orientation_msg__msg__Orientation__FIELD_NAME__quat_w[] = "quat_w";

static rosidl_runtime_c__type_description__Field orientation_msg__msg__Orientation__FIELDS[] = {
  {
    {orientation_msg__msg__Orientation__FIELD_NAME__acc_x, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orientation_msg__msg__Orientation__FIELD_NAME__acc_y, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orientation_msg__msg__Orientation__FIELD_NAME__acc_z, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orientation_msg__msg__Orientation__FIELD_NAME__gyro_x, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orientation_msg__msg__Orientation__FIELD_NAME__gyro_y, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orientation_msg__msg__Orientation__FIELD_NAME__gyro_z, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orientation_msg__msg__Orientation__FIELD_NAME__mag_x, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orientation_msg__msg__Orientation__FIELD_NAME__mag_y, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orientation_msg__msg__Orientation__FIELD_NAME__mag_z, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orientation_msg__msg__Orientation__FIELD_NAME__lin_acc_x, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orientation_msg__msg__Orientation__FIELD_NAME__lin_acc_y, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orientation_msg__msg__Orientation__FIELD_NAME__lin_acc_z, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orientation_msg__msg__Orientation__FIELD_NAME__quat_x, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orientation_msg__msg__Orientation__FIELD_NAME__quat_y, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orientation_msg__msg__Orientation__FIELD_NAME__quat_z, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orientation_msg__msg__Orientation__FIELD_NAME__quat_w, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
orientation_msg__msg__Orientation__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {orientation_msg__msg__Orientation__TYPE_NAME, 31, 31},
      {orientation_msg__msg__Orientation__FIELDS, 16, 16},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Orientation.msg\n"
  "\n"
  "# Acceleration m/s^2\n"
  "float64 acc_x\n"
  "float64 acc_y\n"
  "float64 acc_z\n"
  "\n"
  "# Gyro\n"
  "float64 gyro_x\n"
  "float64 gyro_y\n"
  "float64 gyro_z\n"
  "\n"
  "# Magnetometer\n"
  "float64 mag_x\n"
  "float64 mag_y\n"
  "float64 mag_z\n"
  "\n"
  "# Linear Acceleration\n"
  "float64 lin_acc_x\n"
  "float64 lin_acc_y\n"
  "float64 lin_acc_z\n"
  "\n"
  "# Quaternion for orientation\n"
  "float64 quat_x\n"
  "float64 quat_y\n"
  "float64 quat_z\n"
  "float64 quat_w\n"
  "\n"
  "# Raw Acceleration\n"
  "#string raw_acc_x\n"
  "#string raw_acc_y\n"
  "#string raw_acc_z\n"
  "\n"
  "# Raw Gyro\n"
  "#string raw_gyro_x\n"
  "#string raw_gyro_y\n"
  "#string raw_gyro_z\n"
  "\n"
  "# Raw Magnetometer\n"
  "#string raw_mag_x\n"
  "#string raw_mag_y\n"
  "#string raw_mag_z\n"
  "\n"
  "";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
orientation_msg__msg__Orientation__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {orientation_msg__msg__Orientation__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 579, 579},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
orientation_msg__msg__Orientation__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *orientation_msg__msg__Orientation__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
