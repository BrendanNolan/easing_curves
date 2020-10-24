cmake_minimum_required(VERSION 3.18.4)
project(easing_curves_core)
set(CMAKE_BUILD_TYPE Release)
 
include_directories(.)
 
file(GLOB SOURCES "*.cpp")
 
add_library(easing_curves_core STATIC ${SOURCES})
