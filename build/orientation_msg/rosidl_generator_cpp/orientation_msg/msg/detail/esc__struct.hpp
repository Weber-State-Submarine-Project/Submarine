// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from orientation_msg:msg/Esc.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orientation_msg/msg/esc.hpp"


#ifndef ORIENTATION_MSG__MSG__DETAIL__ESC__STRUCT_HPP_
#define ORIENTATION_MSG__MSG__DETAIL__ESC__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__orientation_msg__msg__Esc __attribute__((deprecated))
#else
# define DEPRECATED__orientation_msg__msg__Esc __declspec(deprecated)
#endif

namespace orientation_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Esc_
{
  using Type = Esc_<ContainerAllocator>;

  explicit Esc_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_selection = "";
      this->power_percentage = 0ll;
    }
  }

  explicit Esc_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : motor_selection(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_selection = "";
      this->power_percentage = 0ll;
    }
  }

  // field types and members
  using _motor_selection_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _motor_selection_type motor_selection;
  using _power_percentage_type =
    int64_t;
  _power_percentage_type power_percentage;

  // setters for named parameter idiom
  Type & set__motor_selection(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->motor_selection = _arg;
    return *this;
  }
  Type & set__power_percentage(
    const int64_t & _arg)
  {
    this->power_percentage = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    orientation_msg::msg::Esc_<ContainerAllocator> *;
  using ConstRawPtr =
    const orientation_msg::msg::Esc_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<orientation_msg::msg::Esc_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<orientation_msg::msg::Esc_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      orientation_msg::msg::Esc_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<orientation_msg::msg::Esc_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      orientation_msg::msg::Esc_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<orientation_msg::msg::Esc_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<orientation_msg::msg::Esc_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<orientation_msg::msg::Esc_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__orientation_msg__msg__Esc
    std::shared_ptr<orientation_msg::msg::Esc_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__orientation_msg__msg__Esc
    std::shared_ptr<orientation_msg::msg::Esc_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Esc_ & other) const
  {
    if (this->motor_selection != other.motor_selection) {
      return false;
    }
    if (this->power_percentage != other.power_percentage) {
      return false;
    }
    return true;
  }
  bool operator!=(const Esc_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Esc_

// alias to use template instance with default allocator
using Esc =
  orientation_msg::msg::Esc_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace orientation_msg

#endif  // ORIENTATION_MSG__MSG__DETAIL__ESC__STRUCT_HPP_
