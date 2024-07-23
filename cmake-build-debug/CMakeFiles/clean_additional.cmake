# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QML_Project_Template_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QML_Project_Template_autogen.dir/ParseCache.txt"
  "QML_Project_Template_autogen"
  )
endif()
