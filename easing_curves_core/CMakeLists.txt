cmake_minimum_required(VERSION 3.18.4)
project(easing_curves_core_proj)
 
file(GLOB SOURCES "*.cpp")
 
add_library(easing_curves_core STATIC ${SOURCES})
target_include_directories(easing_curves_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
