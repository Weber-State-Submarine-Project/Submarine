// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from btcpp_ros2_interfaces:action/Sleep.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "btcpp_ros2_interfaces/action/detail/sleep__functions.h"
#include "btcpp_ros2_interfaces/action/detail/sleep__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace btcpp_ros2_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Sleep_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Sleep_Goal_type_support_ids_t;

static const _Sleep_Goal_type_support_ids_t _Sleep_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Sleep_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Sleep_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Sleep_Goal_type_support_symbol_names_t _Sleep_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, btcpp_ros2_interfaces, action, Sleep_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, btcpp_ros2_interfaces, action, Sleep_Goal)),
  }
};

typedef struct _Sleep_Goal_type_support_data_t
{
  void * data[2];
} _Sleep_Goal_type_support_data_t;

static _Sleep_Goal_type_support_data_t _Sleep_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Sleep_Goal_message_typesupport_map = {
  2,
  "btcpp_ros2_interfaces",
  &_Sleep_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_Sleep_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_Sleep_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Sleep_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Sleep_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &btcpp_ros2_interfaces__action__Sleep_Goal__get_type_hash,
  &btcpp_ros2_interfaces__action__Sleep_Goal__get_type_description,
  &btcpp_ros2_interfaces__action__Sleep_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace btcpp_ros2_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_Goal>()
{
  return &::btcpp_ros2_interfaces::action::rosidl_typesupport_cpp::Sleep_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, btcpp_ros2_interfaces, action, Sleep_Goal)() {
  return get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__functions.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace btcpp_ros2_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Sleep_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Sleep_Result_type_support_ids_t;

static const _Sleep_Result_type_support_ids_t _Sleep_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Sleep_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Sleep_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Sleep_Result_type_support_symbol_names_t _Sleep_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, btcpp_ros2_interfaces, action, Sleep_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, btcpp_ros2_interfaces, action, Sleep_Result)),
  }
};

typedef struct _Sleep_Result_type_support_data_t
{
  void * data[2];
} _Sleep_Result_type_support_data_t;

static _Sleep_Result_type_support_data_t _Sleep_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Sleep_Result_message_typesupport_map = {
  2,
  "btcpp_ros2_interfaces",
  &_Sleep_Result_message_typesupport_ids.typesupport_identifier[0],
  &_Sleep_Result_message_typesupport_symbol_names.symbol_name[0],
  &_Sleep_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Sleep_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Sleep_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &btcpp_ros2_interfaces__action__Sleep_Result__get_type_hash,
  &btcpp_ros2_interfaces__action__Sleep_Result__get_type_description,
  &btcpp_ros2_interfaces__action__Sleep_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace btcpp_ros2_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_Result>()
{
  return &::btcpp_ros2_interfaces::action::rosidl_typesupport_cpp::Sleep_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, btcpp_ros2_interfaces, action, Sleep_Result)() {
  return get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__functions.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace btcpp_ros2_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Sleep_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Sleep_Feedback_type_support_ids_t;

static const _Sleep_Feedback_type_support_ids_t _Sleep_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Sleep_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Sleep_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Sleep_Feedback_type_support_symbol_names_t _Sleep_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, btcpp_ros2_interfaces, action, Sleep_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, btcpp_ros2_interfaces, action, Sleep_Feedback)),
  }
};

typedef struct _Sleep_Feedback_type_support_data_t
{
  void * data[2];
} _Sleep_Feedback_type_support_data_t;

static _Sleep_Feedback_type_support_data_t _Sleep_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Sleep_Feedback_message_typesupport_map = {
  2,
  "btcpp_ros2_interfaces",
  &_Sleep_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_Sleep_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_Sleep_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Sleep_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Sleep_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &btcpp_ros2_interfaces__action__Sleep_Feedback__get_type_hash,
  &btcpp_ros2_interfaces__action__Sleep_Feedback__get_type_description,
  &btcpp_ros2_interfaces__action__Sleep_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace btcpp_ros2_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_Feedback>()
{
  return &::btcpp_ros2_interfaces::action::rosidl_typesupport_cpp::Sleep_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, btcpp_ros2_interfaces, action, Sleep_Feedback)() {
  return get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__functions.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace btcpp_ros2_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Sleep_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Sleep_SendGoal_Request_type_support_ids_t;

static const _Sleep_SendGoal_Request_type_support_ids_t _Sleep_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Sleep_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Sleep_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Sleep_SendGoal_Request_type_support_symbol_names_t _Sleep_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, btcpp_ros2_interfaces, action, Sleep_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, btcpp_ros2_interfaces, action, Sleep_SendGoal_Request)),
  }
};

typedef struct _Sleep_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _Sleep_SendGoal_Request_type_support_data_t;

static _Sleep_SendGoal_Request_type_support_data_t _Sleep_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Sleep_SendGoal_Request_message_typesupport_map = {
  2,
  "btcpp_ros2_interfaces",
  &_Sleep_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Sleep_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Sleep_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Sleep_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Sleep_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &btcpp_ros2_interfaces__action__Sleep_SendGoal_Request__get_type_hash,
  &btcpp_ros2_interfaces__action__Sleep_SendGoal_Request__get_type_description,
  &btcpp_ros2_interfaces__action__Sleep_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace btcpp_ros2_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_SendGoal_Request>()
{
  return &::btcpp_ros2_interfaces::action::rosidl_typesupport_cpp::Sleep_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, btcpp_ros2_interfaces, action, Sleep_SendGoal_Request)() {
  return get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__functions.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace btcpp_ros2_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Sleep_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Sleep_SendGoal_Response_type_support_ids_t;

static const _Sleep_SendGoal_Response_type_support_ids_t _Sleep_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Sleep_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Sleep_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Sleep_SendGoal_Response_type_support_symbol_names_t _Sleep_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, btcpp_ros2_interfaces, action, Sleep_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, btcpp_ros2_interfaces, action, Sleep_SendGoal_Response)),
  }
};

typedef struct _Sleep_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _Sleep_SendGoal_Response_type_support_data_t;

static _Sleep_SendGoal_Response_type_support_data_t _Sleep_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Sleep_SendGoal_Response_message_typesupport_map = {
  2,
  "btcpp_ros2_interfaces",
  &_Sleep_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Sleep_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Sleep_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Sleep_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Sleep_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &btcpp_ros2_interfaces__action__Sleep_SendGoal_Response__get_type_hash,
  &btcpp_ros2_interfaces__action__Sleep_SendGoal_Response__get_type_description,
  &btcpp_ros2_interfaces__action__Sleep_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace btcpp_ros2_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_SendGoal_Response>()
{
  return &::btcpp_ros2_interfaces::action::rosidl_typesupport_cpp::Sleep_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, btcpp_ros2_interfaces, action, Sleep_SendGoal_Response)() {
  return get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__functions.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace btcpp_ros2_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Sleep_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Sleep_SendGoal_Event_type_support_ids_t;

static const _Sleep_SendGoal_Event_type_support_ids_t _Sleep_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Sleep_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Sleep_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Sleep_SendGoal_Event_type_support_symbol_names_t _Sleep_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, btcpp_ros2_interfaces, action, Sleep_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, btcpp_ros2_interfaces, action, Sleep_SendGoal_Event)),
  }
};

typedef struct _Sleep_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _Sleep_SendGoal_Event_type_support_data_t;

static _Sleep_SendGoal_Event_type_support_data_t _Sleep_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Sleep_SendGoal_Event_message_typesupport_map = {
  2,
  "btcpp_ros2_interfaces",
  &_Sleep_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Sleep_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Sleep_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Sleep_SendGoal_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Sleep_SendGoal_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &btcpp_ros2_interfaces__action__Sleep_SendGoal_Event__get_type_hash,
  &btcpp_ros2_interfaces__action__Sleep_SendGoal_Event__get_type_description,
  &btcpp_ros2_interfaces__action__Sleep_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace btcpp_ros2_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_SendGoal_Event>()
{
  return &::btcpp_ros2_interfaces::action::rosidl_typesupport_cpp::Sleep_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, btcpp_ros2_interfaces, action, Sleep_SendGoal_Event)() {
  return get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_SendGoal_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace btcpp_ros2_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Sleep_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Sleep_SendGoal_type_support_ids_t;

static const _Sleep_SendGoal_type_support_ids_t _Sleep_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Sleep_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Sleep_SendGoal_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Sleep_SendGoal_type_support_symbol_names_t _Sleep_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, btcpp_ros2_interfaces, action, Sleep_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, btcpp_ros2_interfaces, action, Sleep_SendGoal)),
  }
};

typedef struct _Sleep_SendGoal_type_support_data_t
{
  void * data[2];
} _Sleep_SendGoal_type_support_data_t;

static _Sleep_SendGoal_type_support_data_t _Sleep_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Sleep_SendGoal_service_typesupport_map = {
  2,
  "btcpp_ros2_interfaces",
  &_Sleep_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_Sleep_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_Sleep_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Sleep_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Sleep_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_SendGoal_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_SendGoal_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_SendGoal_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<btcpp_ros2_interfaces::action::Sleep_SendGoal>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<btcpp_ros2_interfaces::action::Sleep_SendGoal>,
  &btcpp_ros2_interfaces__action__Sleep_SendGoal__get_type_hash,
  &btcpp_ros2_interfaces__action__Sleep_SendGoal__get_type_description,
  &btcpp_ros2_interfaces__action__Sleep_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace btcpp_ros2_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<btcpp_ros2_interfaces::action::Sleep_SendGoal>()
{
  return &::btcpp_ros2_interfaces::action::rosidl_typesupport_cpp::Sleep_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, btcpp_ros2_interfaces, action, Sleep_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<btcpp_ros2_interfaces::action::Sleep_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__functions.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace btcpp_ros2_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Sleep_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Sleep_GetResult_Request_type_support_ids_t;

static const _Sleep_GetResult_Request_type_support_ids_t _Sleep_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Sleep_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Sleep_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Sleep_GetResult_Request_type_support_symbol_names_t _Sleep_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, btcpp_ros2_interfaces, action, Sleep_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, btcpp_ros2_interfaces, action, Sleep_GetResult_Request)),
  }
};

typedef struct _Sleep_GetResult_Request_type_support_data_t
{
  void * data[2];
} _Sleep_GetResult_Request_type_support_data_t;

static _Sleep_GetResult_Request_type_support_data_t _Sleep_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Sleep_GetResult_Request_message_typesupport_map = {
  2,
  "btcpp_ros2_interfaces",
  &_Sleep_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Sleep_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Sleep_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Sleep_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Sleep_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &btcpp_ros2_interfaces__action__Sleep_GetResult_Request__get_type_hash,
  &btcpp_ros2_interfaces__action__Sleep_GetResult_Request__get_type_description,
  &btcpp_ros2_interfaces__action__Sleep_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace btcpp_ros2_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_GetResult_Request>()
{
  return &::btcpp_ros2_interfaces::action::rosidl_typesupport_cpp::Sleep_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, btcpp_ros2_interfaces, action, Sleep_GetResult_Request)() {
  return get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__functions.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace btcpp_ros2_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Sleep_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Sleep_GetResult_Response_type_support_ids_t;

static const _Sleep_GetResult_Response_type_support_ids_t _Sleep_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Sleep_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Sleep_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Sleep_GetResult_Response_type_support_symbol_names_t _Sleep_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, btcpp_ros2_interfaces, action, Sleep_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, btcpp_ros2_interfaces, action, Sleep_GetResult_Response)),
  }
};

typedef struct _Sleep_GetResult_Response_type_support_data_t
{
  void * data[2];
} _Sleep_GetResult_Response_type_support_data_t;

static _Sleep_GetResult_Response_type_support_data_t _Sleep_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Sleep_GetResult_Response_message_typesupport_map = {
  2,
  "btcpp_ros2_interfaces",
  &_Sleep_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Sleep_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Sleep_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Sleep_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Sleep_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &btcpp_ros2_interfaces__action__Sleep_GetResult_Response__get_type_hash,
  &btcpp_ros2_interfaces__action__Sleep_GetResult_Response__get_type_description,
  &btcpp_ros2_interfaces__action__Sleep_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace btcpp_ros2_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_GetResult_Response>()
{
  return &::btcpp_ros2_interfaces::action::rosidl_typesupport_cpp::Sleep_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, btcpp_ros2_interfaces, action, Sleep_GetResult_Response)() {
  return get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__functions.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace btcpp_ros2_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Sleep_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Sleep_GetResult_Event_type_support_ids_t;

static const _Sleep_GetResult_Event_type_support_ids_t _Sleep_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Sleep_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Sleep_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Sleep_GetResult_Event_type_support_symbol_names_t _Sleep_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, btcpp_ros2_interfaces, action, Sleep_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, btcpp_ros2_interfaces, action, Sleep_GetResult_Event)),
  }
};

typedef struct _Sleep_GetResult_Event_type_support_data_t
{
  void * data[2];
} _Sleep_GetResult_Event_type_support_data_t;

static _Sleep_GetResult_Event_type_support_data_t _Sleep_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Sleep_GetResult_Event_message_typesupport_map = {
  2,
  "btcpp_ros2_interfaces",
  &_Sleep_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Sleep_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Sleep_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Sleep_GetResult_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Sleep_GetResult_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &btcpp_ros2_interfaces__action__Sleep_GetResult_Event__get_type_hash,
  &btcpp_ros2_interfaces__action__Sleep_GetResult_Event__get_type_description,
  &btcpp_ros2_interfaces__action__Sleep_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace btcpp_ros2_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_GetResult_Event>()
{
  return &::btcpp_ros2_interfaces::action::rosidl_typesupport_cpp::Sleep_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, btcpp_ros2_interfaces, action, Sleep_GetResult_Event)() {
  return get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_GetResult_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace btcpp_ros2_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Sleep_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Sleep_GetResult_type_support_ids_t;

static const _Sleep_GetResult_type_support_ids_t _Sleep_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Sleep_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Sleep_GetResult_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Sleep_GetResult_type_support_symbol_names_t _Sleep_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, btcpp_ros2_interfaces, action, Sleep_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, btcpp_ros2_interfaces, action, Sleep_GetResult)),
  }
};

typedef struct _Sleep_GetResult_type_support_data_t
{
  void * data[2];
} _Sleep_GetResult_type_support_data_t;

static _Sleep_GetResult_type_support_data_t _Sleep_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Sleep_GetResult_service_typesupport_map = {
  2,
  "btcpp_ros2_interfaces",
  &_Sleep_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_Sleep_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_Sleep_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Sleep_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Sleep_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_GetResult_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_GetResult_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_GetResult_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<btcpp_ros2_interfaces::action::Sleep_GetResult>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<btcpp_ros2_interfaces::action::Sleep_GetResult>,
  &btcpp_ros2_interfaces__action__Sleep_GetResult__get_type_hash,
  &btcpp_ros2_interfaces__action__Sleep_GetResult__get_type_description,
  &btcpp_ros2_interfaces__action__Sleep_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace btcpp_ros2_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<btcpp_ros2_interfaces::action::Sleep_GetResult>()
{
  return &::btcpp_ros2_interfaces::action::rosidl_typesupport_cpp::Sleep_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, btcpp_ros2_interfaces, action, Sleep_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<btcpp_ros2_interfaces::action::Sleep_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__functions.h"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace btcpp_ros2_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Sleep_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Sleep_FeedbackMessage_type_support_ids_t;

static const _Sleep_FeedbackMessage_type_support_ids_t _Sleep_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Sleep_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Sleep_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Sleep_FeedbackMessage_type_support_symbol_names_t _Sleep_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, btcpp_ros2_interfaces, action, Sleep_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, btcpp_ros2_interfaces, action, Sleep_FeedbackMessage)),
  }
};

typedef struct _Sleep_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _Sleep_FeedbackMessage_type_support_data_t;

static _Sleep_FeedbackMessage_type_support_data_t _Sleep_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Sleep_FeedbackMessage_message_typesupport_map = {
  2,
  "btcpp_ros2_interfaces",
  &_Sleep_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_Sleep_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_Sleep_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Sleep_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Sleep_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &btcpp_ros2_interfaces__action__Sleep_FeedbackMessage__get_type_hash,
  &btcpp_ros2_interfaces__action__Sleep_FeedbackMessage__get_type_description,
  &btcpp_ros2_interfaces__action__Sleep_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace btcpp_ros2_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_FeedbackMessage>()
{
  return &::btcpp_ros2_interfaces::action::rosidl_typesupport_cpp::Sleep_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, btcpp_ros2_interfaces, action, Sleep_FeedbackMessage)() {
  return get_message_type_support_handle<btcpp_ros2_interfaces::action::Sleep_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "btcpp_ros2_interfaces/action/detail/sleep__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace btcpp_ros2_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t Sleep_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL,
  &btcpp_ros2_interfaces__action__Sleep__get_type_hash,
  &btcpp_ros2_interfaces__action__Sleep__get_type_description,
  &btcpp_ros2_interfaces__action__Sleep__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace btcpp_ros2_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<btcpp_ros2_interfaces::action::Sleep>()
{
  using ::btcpp_ros2_interfaces::action::rosidl_typesupport_cpp::Sleep_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  Sleep_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::btcpp_ros2_interfaces::action::Sleep::Impl::SendGoalService>();
  Sleep_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::btcpp_ros2_interfaces::action::Sleep::Impl::GetResultService>();
  Sleep_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::btcpp_ros2_interfaces::action::Sleep::Impl::CancelGoalService>();
  Sleep_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::btcpp_ros2_interfaces::action::Sleep::Impl::FeedbackMessage>();
  Sleep_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::btcpp_ros2_interfaces::action::Sleep::Impl::GoalStatusMessage>();
  return &Sleep_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, btcpp_ros2_interfaces, action, Sleep)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<btcpp_ros2_interfaces::action::Sleep>();
}

#ifdef __cplusplus
}
#endif
