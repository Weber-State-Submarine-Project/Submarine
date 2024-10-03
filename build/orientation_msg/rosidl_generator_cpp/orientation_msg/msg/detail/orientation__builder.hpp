// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from orientation_msg:msg/Orientation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orientation_msg/msg/orientation.hpp"


#ifndef ORIENTATION_MSG__MSG__DETAIL__ORIENTATION__BUILDER_HPP_
#define ORIENTATION_MSG__MSG__DETAIL__ORIENTATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "orientation_msg/msg/detail/orientation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace orientation_msg
{

namespace msg
{

namespace builder
{

class Init_Orientation_quat_w
{
public:
  explicit Init_Orientation_quat_w(::orientation_msg::msg::Orientation & msg)
  : msg_(msg)
  {}
  ::orientation_msg::msg::Orientation quat_w(::orientation_msg::msg::Orientation::_quat_w_type arg)
  {
    msg_.quat_w = std::move(arg);
    return std::move(msg_);
  }

private:
  ::orientation_msg::msg::Orientation msg_;
};

class Init_Orientation_quat_z
{
public:
  explicit Init_Orientation_quat_z(::orientation_msg::msg::Orientation & msg)
  : msg_(msg)
  {}
  Init_Orientation_quat_w quat_z(::orientation_msg::msg::Orientation::_quat_z_type arg)
  {
    msg_.quat_z = std::move(arg);
    return Init_Orientation_quat_w(msg_);
  }

private:
  ::orientation_msg::msg::Orientation msg_;
};

class Init_Orientation_quat_y
{
public:
  explicit Init_Orientation_quat_y(::orientation_msg::msg::Orientation & msg)
  : msg_(msg)
  {}
  Init_Orientation_quat_z quat_y(::orientation_msg::msg::Orientation::_quat_y_type arg)
  {
    msg_.quat_y = std::move(arg);
    return Init_Orientation_quat_z(msg_);
  }

private:
  ::orientation_msg::msg::Orientation msg_;
};

class Init_Orientation_quat_x
{
public:
  explicit Init_Orientation_quat_x(::orientation_msg::msg::Orientation & msg)
  : msg_(msg)
  {}
  Init_Orientation_quat_y quat_x(::orientation_msg::msg::Orientation::_quat_x_type arg)
  {
    msg_.quat_x = std::move(arg);
    return Init_Orientation_quat_y(msg_);
  }

private:
  ::orientation_msg::msg::Orientation msg_;
};

class Init_Orientation_lin_acc_z
{
public:
  explicit Init_Orientation_lin_acc_z(::orientation_msg::msg::Orientation & msg)
  : msg_(msg)
  {}
  Init_Orientation_quat_x lin_acc_z(::orientation_msg::msg::Orientation::_lin_acc_z_type arg)
  {
    msg_.lin_acc_z = std::move(arg);
    return Init_Orientation_quat_x(msg_);
  }

private:
  ::orientation_msg::msg::Orientation msg_;
};

class Init_Orientation_lin_acc_y
{
public:
  explicit Init_Orientation_lin_acc_y(::orientation_msg::msg::Orientation & msg)
  : msg_(msg)
  {}
  Init_Orientation_lin_acc_z lin_acc_y(::orientation_msg::msg::Orientation::_lin_acc_y_type arg)
  {
    msg_.lin_acc_y = std::move(arg);
    return Init_Orientation_lin_acc_z(msg_);
  }

private:
  ::orientation_msg::msg::Orientation msg_;
};

class Init_Orientation_lin_acc_x
{
public:
  explicit Init_Orientation_lin_acc_x(::orientation_msg::msg::Orientation & msg)
  : msg_(msg)
  {}
  Init_Orientation_lin_acc_y lin_acc_x(::orientation_msg::msg::Orientation::_lin_acc_x_type arg)
  {
    msg_.lin_acc_x = std::move(arg);
    return Init_Orientation_lin_acc_y(msg_);
  }

private:
  ::orientation_msg::msg::Orientation msg_;
};

class Init_Orientation_mag_z
{
public:
  explicit Init_Orientation_mag_z(::orientation_msg::msg::Orientation & msg)
  : msg_(msg)
  {}
  Init_Orientation_lin_acc_x mag_z(::orientation_msg::msg::Orientation::_mag_z_type arg)
  {
    msg_.mag_z = std::move(arg);
    return Init_Orientation_lin_acc_x(msg_);
  }

private:
  ::orientation_msg::msg::Orientation msg_;
};

class Init_Orientation_mag_y
{
public:
  explicit Init_Orientation_mag_y(::orientation_msg::msg::Orientation & msg)
  : msg_(msg)
  {}
  Init_Orientation_mag_z mag_y(::orientation_msg::msg::Orientation::_mag_y_type arg)
  {
    msg_.mag_y = std::move(arg);
    return Init_Orientation_mag_z(msg_);
  }

private:
  ::orientation_msg::msg::Orientation msg_;
};

class Init_Orientation_mag_x
{
public:
  explicit Init_Orientation_mag_x(::orientation_msg::msg::Orientation & msg)
  : msg_(msg)
  {}
  Init_Orientation_mag_y mag_x(::orientation_msg::msg::Orientation::_mag_x_type arg)
  {
    msg_.mag_x = std::move(arg);
    return Init_Orientation_mag_y(msg_);
  }

private:
  ::orientation_msg::msg::Orientation msg_;
};

class Init_Orientation_gyro_z
{
public:
  explicit Init_Orientation_gyro_z(::orientation_msg::msg::Orientation & msg)
  : msg_(msg)
  {}
  Init_Orientation_mag_x gyro_z(::orientation_msg::msg::Orientation::_gyro_z_type arg)
  {
    msg_.gyro_z = std::move(arg);
    return Init_Orientation_mag_x(msg_);
  }

private:
  ::orientation_msg::msg::Orientation msg_;
};

class Init_Orientation_gyro_y
{
public:
  explicit Init_Orientation_gyro_y(::orientation_msg::msg::Orientation & msg)
  : msg_(msg)
  {}
  Init_Orientation_gyro_z gyro_y(::orientation_msg::msg::Orientation::_gyro_y_type arg)
  {
    msg_.gyro_y = std::move(arg);
    return Init_Orientation_gyro_z(msg_);
  }

private:
  ::orientation_msg::msg::Orientation msg_;
};

class Init_Orientation_gyro_x
{
public:
  explicit Init_Orientation_gyro_x(::orientation_msg::msg::Orientation & msg)
  : msg_(msg)
  {}
  Init_Orientation_gyro_y gyro_x(::orientation_msg::msg::Orientation::_gyro_x_type arg)
  {
    msg_.gyro_x = std::move(arg);
    return Init_Orientation_gyro_y(msg_);
  }

private:
  ::orientation_msg::msg::Orientation msg_;
};

class Init_Orientation_acc_z
{
public:
  explicit Init_Orientation_acc_z(::orientation_msg::msg::Orientation & msg)
  : msg_(msg)
  {}
  Init_Orientation_gyro_x acc_z(::orientation_msg::msg::Orientation::_acc_z_type arg)
  {
    msg_.acc_z = std::move(arg);
    return Init_Orientation_gyro_x(msg_);
  }

private:
  ::orientation_msg::msg::Orientation msg_;
};

class Init_Orientation_acc_y
{
public:
  explicit Init_Orientation_acc_y(::orientation_msg::msg::Orientation & msg)
  : msg_(msg)
  {}
  Init_Orientation_acc_z acc_y(::orientation_msg::msg::Orientation::_acc_y_type arg)
  {
    msg_.acc_y = std::move(arg);
    return Init_Orientation_acc_z(msg_);
  }

private:
  ::orientation_msg::msg::Orientation msg_;
};

class Init_Orientation_acc_x
{
public:
  Init_Orientation_acc_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Orientation_acc_y acc_x(::orientation_msg::msg::Orientation::_acc_x_type arg)
  {
    msg_.acc_x = std::move(arg);
    return Init_Orientation_acc_y(msg_);
  }

private:
  ::orientation_msg::msg::Orientation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::orientation_msg::msg::Orientation>()
{
  return orientation_msg::msg::builder::Init_Orientation_acc_x();
}

}  // namespace orientation_msg

#endif  // ORIENTATION_MSG__MSG__DETAIL__ORIENTATION__BUILDER_HPP_
