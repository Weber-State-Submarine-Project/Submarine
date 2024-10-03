// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from orientation_msg:msg/Esc.idl
// generated code does not contain a copyright notice
#include "orientation_msg/msg/detail/esc__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `motor_selection`
#include "rosidl_runtime_c/string_functions.h"

bool
orientation_msg__msg__Esc__init(orientation_msg__msg__Esc * msg)
{
  if (!msg) {
    return false;
  }
  // motor_selection
  if (!rosidl_runtime_c__String__init(&msg->motor_selection)) {
    orientation_msg__msg__Esc__fini(msg);
    return false;
  }
  // power_percentage
  return true;
}

void
orientation_msg__msg__Esc__fini(orientation_msg__msg__Esc * msg)
{
  if (!msg) {
    return;
  }
  // motor_selection
  rosidl_runtime_c__String__fini(&msg->motor_selection);
  // power_percentage
}

bool
orientation_msg__msg__Esc__are_equal(const orientation_msg__msg__Esc * lhs, const orientation_msg__msg__Esc * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // motor_selection
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->motor_selection), &(rhs->motor_selection)))
  {
    return false;
  }
  // power_percentage
  if (lhs->power_percentage != rhs->power_percentage) {
    return false;
  }
  return true;
}

bool
orientation_msg__msg__Esc__copy(
  const orientation_msg__msg__Esc * input,
  orientation_msg__msg__Esc * output)
{
  if (!input || !output) {
    return false;
  }
  // motor_selection
  if (!rosidl_runtime_c__String__copy(
      &(input->motor_selection), &(output->motor_selection)))
  {
    return false;
  }
  // power_percentage
  output->power_percentage = input->power_percentage;
  return true;
}

orientation_msg__msg__Esc *
orientation_msg__msg__Esc__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orientation_msg__msg__Esc * msg = (orientation_msg__msg__Esc *)allocator.allocate(sizeof(orientation_msg__msg__Esc), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(orientation_msg__msg__Esc));
  bool success = orientation_msg__msg__Esc__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
orientation_msg__msg__Esc__destroy(orientation_msg__msg__Esc * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    orientation_msg__msg__Esc__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
orientation_msg__msg__Esc__Sequence__init(orientation_msg__msg__Esc__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orientation_msg__msg__Esc * data = NULL;

  if (size) {
    data = (orientation_msg__msg__Esc *)allocator.zero_allocate(size, sizeof(orientation_msg__msg__Esc), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = orientation_msg__msg__Esc__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        orientation_msg__msg__Esc__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
orientation_msg__msg__Esc__Sequence__fini(orientation_msg__msg__Esc__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      orientation_msg__msg__Esc__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

orientation_msg__msg__Esc__Sequence *
orientation_msg__msg__Esc__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orientation_msg__msg__Esc__Sequence * array = (orientation_msg__msg__Esc__Sequence *)allocator.allocate(sizeof(orientation_msg__msg__Esc__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = orientation_msg__msg__Esc__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
orientation_msg__msg__Esc__Sequence__destroy(orientation_msg__msg__Esc__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    orientation_msg__msg__Esc__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
orientation_msg__msg__Esc__Sequence__are_equal(const orientation_msg__msg__Esc__Sequence * lhs, const orientation_msg__msg__Esc__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!orientation_msg__msg__Esc__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
orientation_msg__msg__Esc__Sequence__copy(
  const orientation_msg__msg__Esc__Sequence * input,
  orientation_msg__msg__Esc__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(orientation_msg__msg__Esc);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    orientation_msg__msg__Esc * data =
      (orientation_msg__msg__Esc *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!orientation_msg__msg__Esc__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          orientation_msg__msg__Esc__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!orientation_msg__msg__Esc__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
