#ifndef ROS_BT__VISIBILITY_CONTROL_H_
#define ROS_BT__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROS_BT_EXPORT __attribute__ ((dllexport))
    #define ROS_BT_IMPORT __attribute__ ((dllimport))
  #else
    #define ROS_BT_EXPORT __declspec(dllexport)
    #define ROS_BT_IMPORT __declspec(dllimport)
  #endif
  #ifdef ROS_BT_BUILDING_DLL
    #define ROS_BT_PUBLIC ROS_BT_EXPORT
  #else
    #define ROS_BT_PUBLIC ROS_BT_IMPORT
  #endif
  #define ROS_BT_PUBLIC_TYPE ROS_BT_PUBLIC
  #define ROS_BT_LOCAL
#else
  #define ROS_BT_EXPORT __attribute__ ((visibility("default")))
  #define ROS_BT_IMPORT
  #if __GNUC__ >= 4
    #define ROS_BT_PUBLIC __attribute__ ((visibility("default")))
    #define ROS_BT_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ROS_BT_PUBLIC
    #define ROS_BT_LOCAL
  #endif
  #define ROS_BT_PUBLIC_TYPE
#endif

#ifdef __cplusplus
}
#endif

#endif  // ROS_BT__VISIBILITY_CONTROL_H_
