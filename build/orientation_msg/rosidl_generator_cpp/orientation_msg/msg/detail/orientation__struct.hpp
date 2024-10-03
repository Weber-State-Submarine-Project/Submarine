// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from orientation_msg:msg/Orientation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orientation_msg/msg/orientation.hpp"


#ifndef ORIENTATION_MSG__MSG__DETAIL__ORIENTATION__STRUCT_HPP_
#define ORIENTATION_MSG__MSG__DETAIL__ORIENTATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__orientation_msg__msg__Orientation __attribute__((deprecated))
#else
# define DEPRECATED__orientation_msg__msg__Orientation __declspec(deprecated)
#endif

namespace orientation_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Orientation_
{
  using Type = Orientation_<ContainerAllocator>;

  explicit Orientation_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->acc_x = 0.0;
      this->acc_y = 0.0;
      this->acc_z = 0.0;
      this->gyro_x = 0.0;
      this->gyro_y = 0.0;
      this->gyro_z = 0.0;
      this->mag_x = 0.0;
      this->mag_y = 0.0;
      this->mag_z = 0.0;
      this->lin_acc_x = 0.0;
      this->lin_acc_y = 0.0;
      this->lin_acc_z = 0.0;
      this->quat_x = 0.0;
      this->quat_y = 0.0;
      this->quat_z = 0.0;
      this->quat_w = 0.0;
    }
  }

  explicit Orientation_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->acc_x = 0.0;
      this->acc_y = 0.0;
      this->acc_z = 0.0;
      this->gyro_x = 0.0;
      this->gyro_y = 0.0;
      this->gyro_z = 0.0;
      this->mag_x = 0.0;
      this->mag_y = 0.0;
      this->mag_z = 0.0;
      this->lin_acc_x = 0.0;
      this->lin_acc_y = 0.0;
      this->lin_acc_z = 0.0;
      this->quat_x = 0.0;
      this->quat_y = 0.0;
      this->quat_z = 0.0;
      this->quat_w = 0.0;
    }
  }

  // field types and members
  using _acc_x_type =
    double;
  _acc_x_type acc_x;
  using _acc_y_type =
    double;
  _acc_y_type acc_y;
  using _acc_z_type =
    double;
  _acc_z_type acc_z;
  using _gyro_x_type =
    double;
  _gyro_x_type gyro_x;
  using _gyro_y_type =
    double;
  _gyro_y_type gyro_y;
  using _gyro_z_type =
    double;
  _gyro_z_type gyro_z;
  using _mag_x_type =
    double;
  _mag_x_type mag_x;
  using _mag_y_type =
    double;
  _mag_y_type mag_y;
  using _mag_z_type =
    double;
  _mag_z_type mag_z;
  using _lin_acc_x_type =
    double;
  _lin_acc_x_type lin_acc_x;
  using _lin_acc_y_type =
    double;
  _lin_acc_y_type lin_acc_y;
  using _lin_acc_z_type =
    double;
  _lin_acc_z_type lin_acc_z;
  using _quat_x_type =
    double;
  _quat_x_type quat_x;
  using _quat_y_type =
    double;
  _quat_y_type quat_y;
  using _quat_z_type =
    double;
  _quat_z_type quat_z;
  using _quat_w_type =
    double;
  _quat_w_type quat_w;

  // setters for named parameter idiom
  Type & set__acc_x(
    const double & _arg)
  {
    this->acc_x = _arg;
    return *this;
  }
  Type & set__acc_y(
    const double & _arg)
  {
    this->acc_y = _arg;
    return *this;
  }
  Type & set__acc_z(
    const double & _arg)
  {
    this->acc_z = _arg;
    return *this;
  }
  Type & set__gyro_x(
    const double & _arg)
  {
    this->gyro_x = _arg;
    return *this;
  }
  Type & set__gyro_y(
    const double & _arg)
  {
    this->gyro_y = _arg;
    return *this;
  }
  Type & set__gyro_z(
    const double & _arg)
  {
    this->gyro_z = _arg;
    return *this;
  }
  Type & set__mag_x(
    const double & _arg)
  {
    this->mag_x = _arg;
    return *this;
  }
  Type & set__mag_y(
    const double & _arg)
  {
    this->mag_y = _arg;
    return *this;
  }
  Type & set__mag_z(
    const double & _arg)
  {
    this->mag_z = _arg;
    return *this;
  }
  Type & set__lin_acc_x(
    const double & _arg)
  {
    this->lin_acc_x = _arg;
    return *this;
  }
  Type & set__lin_acc_y(
    const double & _arg)
  {
    this->lin_acc_y = _arg;
    return *this;
  }
  Type & set__lin_acc_z(
    const double & _arg)
  {
    this->lin_acc_z = _arg;
    return *this;
  }
  Type & set__quat_x(
    const double & _arg)
  {
    this->quat_x = _arg;
    return *this;
  }
  Type & set__quat_y(
    const double & _arg)
  {
    this->quat_y = _arg;
    return *this;
  }
  Type & set__quat_z(
    const double & _arg)
  {
    this->quat_z = _arg;
    return *this;
  }
  Type & set__quat_w(
    const double & _arg)
  {
    this->quat_w = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    orientation_msg::msg::Orientation_<ContainerAllocator> *;
  using ConstRawPtr =
    const orientation_msg::msg::Orientation_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<orientation_msg::msg::Orientation_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<orientation_msg::msg::Orientation_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      orientation_msg::msg::Orientation_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<orientation_msg::msg::Orientation_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      orientation_msg::msg::Orientation_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<orientation_msg::msg::Orientation_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<orientation_msg::msg::Orientation_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<orientation_msg::msg::Orientation_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__orientation_msg__msg__Orientation
    std::shared_ptr<orientation_msg::msg::Orientation_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__orientation_msg__msg__Orientation
    std::shared_ptr<orientation_msg::msg::Orientation_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Orientation_ & other) const
  {
    if (this->acc_x != other.acc_x) {
      return false;
    }
    if (this->acc_y != other.acc_y) {
      return false;
    }
    if (this->acc_z != other.acc_z) {
      return false;
    }
    if (this->gyro_x != other.gyro_x) {
      return false;
    }
    if (this->gyro_y != other.gyro_y) {
      return false;
    }
    if (this->gyro_z != other.gyro_z) {
      return false;
    }
    if (this->mag_x != other.mag_x) {
      return false;
    }
    if (this->mag_y != other.mag_y) {
      return false;
    }
    if (this->mag_z != other.mag_z) {
      return false;
    }
    if (this->lin_acc_x != other.lin_acc_x) {
      return false;
    }
    if (this->lin_acc_y != other.lin_acc_y) {
      return false;
    }
    if (this->lin_acc_z != other.lin_acc_z) {
      return false;
    }
    if (this->quat_x != other.quat_x) {
      return false;
    }
    if (this->quat_y != other.quat_y) {
      return false;
    }
    if (this->quat_z != other.quat_z) {
      return false;
    }
    if (this->quat_w != other.quat_w) {
      return false;
    }
    return true;
  }
  bool operator!=(const Orientation_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Orientation_

// alias to use template instance with default allocator
using Orientation =
  orientation_msg::msg::Orientation_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace orientation_msg

#endif  // ORIENTATION_MSG__MSG__DETAIL__ORIENTATION__STRUCT_HPP_
