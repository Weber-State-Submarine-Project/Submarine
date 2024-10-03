// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from orientation_msg:msg/Orientation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orientation_msg/msg/orientation.hpp"


#ifndef ORIENTATION_MSG__MSG__DETAIL__ORIENTATION__TRAITS_HPP_
#define ORIENTATION_MSG__MSG__DETAIL__ORIENTATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "orientation_msg/msg/detail/orientation__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace orientation_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Orientation & msg,
  std::ostream & out)
{
  out << "{";
  // member: acc_x
  {
    out << "acc_x: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_x, out);
    out << ", ";
  }

  // member: acc_y
  {
    out << "acc_y: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_y, out);
    out << ", ";
  }

  // member: acc_z
  {
    out << "acc_z: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_z, out);
    out << ", ";
  }

  // member: gyro_x
  {
    out << "gyro_x: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_x, out);
    out << ", ";
  }

  // member: gyro_y
  {
    out << "gyro_y: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_y, out);
    out << ", ";
  }

  // member: gyro_z
  {
    out << "gyro_z: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_z, out);
    out << ", ";
  }

  // member: mag_x
  {
    out << "mag_x: ";
    rosidl_generator_traits::value_to_yaml(msg.mag_x, out);
    out << ", ";
  }

  // member: mag_y
  {
    out << "mag_y: ";
    rosidl_generator_traits::value_to_yaml(msg.mag_y, out);
    out << ", ";
  }

  // member: mag_z
  {
    out << "mag_z: ";
    rosidl_generator_traits::value_to_yaml(msg.mag_z, out);
    out << ", ";
  }

  // member: lin_acc_x
  {
    out << "lin_acc_x: ";
    rosidl_generator_traits::value_to_yaml(msg.lin_acc_x, out);
    out << ", ";
  }

  // member: lin_acc_y
  {
    out << "lin_acc_y: ";
    rosidl_generator_traits::value_to_yaml(msg.lin_acc_y, out);
    out << ", ";
  }

  // member: lin_acc_z
  {
    out << "lin_acc_z: ";
    rosidl_generator_traits::value_to_yaml(msg.lin_acc_z, out);
    out << ", ";
  }

  // member: quat_x
  {
    out << "quat_x: ";
    rosidl_generator_traits::value_to_yaml(msg.quat_x, out);
    out << ", ";
  }

  // member: quat_y
  {
    out << "quat_y: ";
    rosidl_generator_traits::value_to_yaml(msg.quat_y, out);
    out << ", ";
  }

  // member: quat_z
  {
    out << "quat_z: ";
    rosidl_generator_traits::value_to_yaml(msg.quat_z, out);
    out << ", ";
  }

  // member: quat_w
  {
    out << "quat_w: ";
    rosidl_generator_traits::value_to_yaml(msg.quat_w, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Orientation & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: acc_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acc_x: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_x, out);
    out << "\n";
  }

  // member: acc_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acc_y: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_y, out);
    out << "\n";
  }

  // member: acc_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acc_z: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_z, out);
    out << "\n";
  }

  // member: gyro_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_x: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_x, out);
    out << "\n";
  }

  // member: gyro_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_y: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_y, out);
    out << "\n";
  }

  // member: gyro_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_z: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_z, out);
    out << "\n";
  }

  // member: mag_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mag_x: ";
    rosidl_generator_traits::value_to_yaml(msg.mag_x, out);
    out << "\n";
  }

  // member: mag_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mag_y: ";
    rosidl_generator_traits::value_to_yaml(msg.mag_y, out);
    out << "\n";
  }

  // member: mag_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mag_z: ";
    rosidl_generator_traits::value_to_yaml(msg.mag_z, out);
    out << "\n";
  }

  // member: lin_acc_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lin_acc_x: ";
    rosidl_generator_traits::value_to_yaml(msg.lin_acc_x, out);
    out << "\n";
  }

  // member: lin_acc_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lin_acc_y: ";
    rosidl_generator_traits::value_to_yaml(msg.lin_acc_y, out);
    out << "\n";
  }

  // member: lin_acc_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lin_acc_z: ";
    rosidl_generator_traits::value_to_yaml(msg.lin_acc_z, out);
    out << "\n";
  }

  // member: quat_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quat_x: ";
    rosidl_generator_traits::value_to_yaml(msg.quat_x, out);
    out << "\n";
  }

  // member: quat_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quat_y: ";
    rosidl_generator_traits::value_to_yaml(msg.quat_y, out);
    out << "\n";
  }

  // member: quat_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quat_z: ";
    rosidl_generator_traits::value_to_yaml(msg.quat_z, out);
    out << "\n";
  }

  // member: quat_w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quat_w: ";
    rosidl_generator_traits::value_to_yaml(msg.quat_w, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Orientation & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace orientation_msg

namespace rosidl_generator_traits
{

[[deprecated("use orientation_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const orientation_msg::msg::Orientation & msg,
  std::ostream & out, size_t indentation = 0)
{
  orientation_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use orientation_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const orientation_msg::msg::Orientation & msg)
{
  return orientation_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<orientation_msg::msg::Orientation>()
{
  return "orientation_msg::msg::Orientation";
}

template<>
inline const char * name<orientation_msg::msg::Orientation>()
{
  return "orientation_msg/msg/Orientation";
}

template<>
struct has_fixed_size<orientation_msg::msg::Orientation>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<orientation_msg::msg::Orientation>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<orientation_msg::msg::Orientation>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ORIENTATION_MSG__MSG__DETAIL__ORIENTATION__TRAITS_HPP_
