target_sources(
  espresso_script_interface
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/initialize.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/CudaInitHandle.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/Globals.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/System.cpp)
