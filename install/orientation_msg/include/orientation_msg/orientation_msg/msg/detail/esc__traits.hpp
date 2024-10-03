// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from orientation_msg:msg/Esc.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orientation_msg/msg/esc.hpp"


#ifndef ORIENTATION_MSG__MSG__DETAIL__ESC__TRAITS_HPP_
#define ORIENTATION_MSG__MSG__DETAIL__ESC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "orientation_msg/msg/detail/esc__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace orientation_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Esc & msg,
  std::ostream & out)
{
  out << "{";
  // member: motor_selection
  {
    out << "motor_selection: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_selection, out);
    out << ", ";
  }

  // member: power_percentage
  {
    out << "power_percentage: ";
    rosidl_generator_traits::value_to_yaml(msg.power_percentage, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Esc & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: motor_selection
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_selection: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_selection, out);
    out << "\n";
  }

  // member: power_percentage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "power_percentage: ";
    rosidl_generator_traits::value_to_yaml(msg.power_percentage, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Esc & msg, bool use_flow_style = false)
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
  const orientation_msg::msg::Esc & msg,
  std::ostream & out, size_t indentation = 0)
{
  orientation_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use orientation_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const orientation_msg::msg::Esc & msg)
{
  return orientation_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<orientation_msg::msg::Esc>()
{
  return "orientation_msg::msg::Esc";
}

template<>
inline const char * name<orientation_msg::msg::Esc>()
{
  return "orientation_msg/msg/Esc";
}

template<>
struct has_fixed_size<orientation_msg::msg::Esc>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<orientation_msg::msg::Esc>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<orientation_msg::msg::Esc>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ORIENTATION_MSG__MSG__DETAIL__ESC__TRAITS_HPP_
