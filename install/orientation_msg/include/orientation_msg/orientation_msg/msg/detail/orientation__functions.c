// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from orientation_msg:msg/Orientation.idl
// generated code does not contain a copyright notice
#include "orientation_msg/msg/detail/orientation__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
orientation_msg__msg__Orientation__init(orientation_msg__msg__Orientation * msg)
{
  if (!msg) {
    return false;
  }
  // acc_x
  // acc_y
  // acc_z
  // gyro_x
  // gyro_y
  // gyro_z
  // mag_x
  // mag_y
  // mag_z
  // lin_acc_x
  // lin_acc_y
  // lin_acc_z
  // quat_x
  // quat_y
  // quat_z
  // quat_w
  return true;
}

void
orientation_msg__msg__Orientation__fini(orientation_msg__msg__Orientation * msg)
{
  if (!msg) {
    return;
  }
  // acc_x
  // acc_y
  // acc_z
  // gyro_x
  // gyro_y
  // gyro_z
  // mag_x
  // mag_y
  // mag_z
  // lin_acc_x
  // lin_acc_y
  // lin_acc_z
  // quat_x
  // quat_y
  // quat_z
  // quat_w
}

bool
orientation_msg__msg__Orientation__are_equal(const orientation_msg__msg__Orientation * lhs, const orientation_msg__msg__Orientation * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // acc_x
  if (lhs->acc_x != rhs->acc_x) {
    return false;
  }
  // acc_y
  if (lhs->acc_y != rhs->acc_y) {
    return false;
  }
  // acc_z
  if (lhs->acc_z != rhs->acc_z) {
    return false;
  }
  // gyro_x
  if (lhs->gyro_x != rhs->gyro_x) {
    return false;
  }
  // gyro_y
  if (lhs->gyro_y != rhs->gyro_y) {
    return false;
  }
  // gyro_z
  if (lhs->gyro_z != rhs->gyro_z) {
    return false;
  }
  // mag_x
  if (lhs->mag_x != rhs->mag_x) {
    return false;
  }
  // mag_y
  if (lhs->mag_y != rhs->mag_y) {
    return false;
  }
  // mag_z
  if (lhs->mag_z != rhs->mag_z) {
    return false;
  }
  // lin_acc_x
  if (lhs->lin_acc_x != rhs->lin_acc_x) {
    return false;
  }
  // lin_acc_y
  if (lhs->lin_acc_y != rhs->lin_acc_y) {
    return false;
  }
  // lin_acc_z
  if (lhs->lin_acc_z != rhs->lin_acc_z) {
    return false;
  }
  // quat_x
  if (lhs->quat_x != rhs->quat_x) {
    return false;
  }
  // quat_y
  if (lhs->quat_y != rhs->quat_y) {
    return false;
  }
  // quat_z
  if (lhs->quat_z != rhs->quat_z) {
    return false;
  }
  // quat_w
  if (lhs->quat_w != rhs->quat_w) {
    return false;
  }
  return true;
}

bool
orientation_msg__msg__Orientation__copy(
  const orientation_msg__msg__Orientation * input,
  orientation_msg__msg__Orientation * output)
{
  if (!input || !output) {
    return false;
  }
  // acc_x
  output->acc_x = input->acc_x;
  // acc_y
  output->acc_y = input->acc_y;
  // acc_z
  output->acc_z = input->acc_z;
  // gyro_x
  output->gyro_x = input->gyro_x;
  // gyro_y
  output->gyro_y = input->gyro_y;
  // gyro_z
  output->gyro_z = input->gyro_z;
  // mag_x
  output->mag_x = input->mag_x;
  // mag_y
  output->mag_y = input->mag_y;
  // mag_z
  output->mag_z = input->mag_z;
  // lin_acc_x
  output->lin_acc_x = input->lin_acc_x;
  // lin_acc_y
  output->lin_acc_y = input->lin_acc_y;
  // lin_acc_z
  output->lin_acc_z = input->lin_acc_z;
  // quat_x
  output->quat_x = input->quat_x;
  // quat_y
  output->quat_y = input->quat_y;
  // quat_z
  output->quat_z = input->quat_z;
  // quat_w
  output->quat_w = input->quat_w;
  return true;
}

orientation_msg__msg__Orientation *
orientation_msg__msg__Orientation__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orientation_msg__msg__Orientation * msg = (orientation_msg__msg__Orientation *)allocator.allocate(sizeof(orientation_msg__msg__Orientation), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(orientation_msg__msg__Orientation));
  bool success = orientation_msg__msg__Orientation__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
orientation_msg__msg__Orientation__destroy(orientation_msg__msg__Orientation * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    orientation_msg__msg__Orientation__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
orientation_msg__msg__Orientation__Sequence__init(orientation_msg__msg__Orientation__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orientation_msg__msg__Orientation * data = NULL;

  if (size) {
    data = (orientation_msg__msg__Orientation *)allocator.zero_allocate(size, sizeof(orientation_msg__msg__Orientation), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = orientation_msg__msg__Orientation__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        orientation_msg__msg__Orientation__fini(&data[i - 1]);
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
orientation_msg__msg__Orientation__Sequence__fini(orientation_msg__msg__Orientation__Sequence * array)
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
      orientation_msg__msg__Orientation__fini(&array->data[i]);
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

orientation_msg__msg__Orientation__Sequence *
orientation_msg__msg__Orientation__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orientation_msg__msg__Orientation__Sequence * array = (orientation_msg__msg__Orientation__Sequence *)allocator.allocate(sizeof(orientation_msg__msg__Orientation__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = orientation_msg__msg__Orientation__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
orientation_msg__msg__Orientation__Sequence__destroy(orientation_msg__msg__Orientation__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    orientation_msg__msg__Orientation__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
orientation_msg__msg__Orientation__Sequence__are_equal(const orientation_msg__msg__Orientation__Sequence * lhs, const orientation_msg__msg__Orientation__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!orientation_msg__msg__Orientation__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
orientation_msg__msg__Orientation__Sequence__copy(
  const orientation_msg__msg__Orientation__Sequence * input,
  orientation_msg__msg__Orientation__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(orientation_msg__msg__Orientation);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    orientation_msg__msg__Orientation * data =
      (orientation_msg__msg__Orientation *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!orientation_msg__msg__Orientation__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          orientation_msg__msg__Orientation__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!orientation_msg__msg__Orientation__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
