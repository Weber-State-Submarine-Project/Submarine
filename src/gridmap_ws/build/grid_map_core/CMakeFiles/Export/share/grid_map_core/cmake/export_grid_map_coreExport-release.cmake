#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "grid_map_core::grid_map_core" for configuration "Release"
set_property(TARGET grid_map_core::grid_map_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(grid_map_core::grid_map_core PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libgrid_map_core.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS grid_map_core::grid_map_core )
list(APPEND _IMPORT_CHECK_FILES_FOR_grid_map_core::grid_map_core "${_IMPORT_PREFIX}/lib/libgrid_map_core.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
