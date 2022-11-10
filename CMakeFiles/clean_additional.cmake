# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\Fractures_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Fractures_autogen.dir\\ParseCache.txt"
  "Fractures_autogen"
  )
endif()
