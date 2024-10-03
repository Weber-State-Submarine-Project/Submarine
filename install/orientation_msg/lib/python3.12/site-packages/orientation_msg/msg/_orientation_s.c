// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from orientation_msg:msg/Orientation.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "orientation_msg/msg/detail/orientation__struct.h"
#include "orientation_msg/msg/detail/orientation__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool orientation_msg__msg__orientation__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[45];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("orientation_msg.msg._orientation.Orientation", full_classname_dest, 44) == 0);
  }
  orientation_msg__msg__Orientation * ros_message = _ros_message;
  {  // acc_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "acc_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->acc_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // acc_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "acc_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->acc_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // acc_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "acc_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->acc_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gyro_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyro_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gyro_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gyro_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyro_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gyro_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gyro_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "gyro_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gyro_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mag_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "mag_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mag_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mag_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "mag_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mag_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mag_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "mag_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mag_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // lin_acc_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "lin_acc_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->lin_acc_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // lin_acc_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "lin_acc_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->lin_acc_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // lin_acc_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "lin_acc_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->lin_acc_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // quat_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "quat_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->quat_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // quat_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "quat_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->quat_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // quat_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "quat_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->quat_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // quat_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "quat_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->quat_w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * orientation_msg__msg__orientation__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Orientation */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("orientation_msg.msg._orientation");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Orientation");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  orientation_msg__msg__Orientation * ros_message = (orientation_msg__msg__Orientation *)raw_ros_message;
  {  // acc_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->acc_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "acc_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // acc_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->acc_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "acc_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // acc_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->acc_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "acc_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gyro_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gyro_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyro_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gyro_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gyro_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyro_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gyro_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gyro_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gyro_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mag_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mag_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mag_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mag_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mag_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mag_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mag_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mag_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mag_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lin_acc_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->lin_acc_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lin_acc_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lin_acc_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->lin_acc_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lin_acc_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lin_acc_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->lin_acc_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lin_acc_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // quat_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->quat_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "quat_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // quat_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->quat_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "quat_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // quat_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->quat_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "quat_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // quat_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->quat_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "quat_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
