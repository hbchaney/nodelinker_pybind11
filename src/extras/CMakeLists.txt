add_library(utls STATIC Node.cpp NodeMap.cpp)
set_property(TARGET utls PROPERTY POSITION_INDEPENDENT_CODE ON)