// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from orientation_msg:msg/Esc.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orientation_msg/msg/esc.hpp"


#ifndef ORIENTATION_MSG__MSG__DETAIL__ESC__BUILDER_HPP_
#define ORIENTATION_MSG__MSG__DETAIL__ESC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "orientation_msg/msg/detail/esc__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace orientation_msg
{

namespace msg
{

namespace builder
{

class Init_Esc_power_percentage
{
public:
  explicit Init_Esc_power_percentage(::orientation_msg::msg::Esc & msg)
  : msg_(msg)
  {}
  ::orientation_msg::msg::Esc power_percentage(::orientation_msg::msg::Esc::_power_percentage_type arg)
  {
    msg_.power_percentage = std::move(arg);
    return std::move(msg_);
  }

private:
  ::orientation_msg::msg::Esc msg_;
};

class Init_Esc_motor_selection
{
public:
  Init_Esc_motor_selection()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Esc_power_percentage motor_selection(::orientation_msg::msg::Esc::_motor_selection_type arg)
  {
    msg_.motor_selection = std::move(arg);
    return Init_Esc_power_percentage(msg_);
  }

private:
  ::orientation_msg::msg::Esc msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::orientation_msg::msg::Esc>()
{
  return orientation_msg::msg::builder::Init_Esc_motor_selection();
}

}  // namespace orientation_msg

#endif  // ORIENTATION_MSG__MSG__DETAIL__ESC__BUILDER_HPP_
