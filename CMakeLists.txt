cmake_minimum_required(VERSION 3.18.4)
project(subdirs_proj)
set(CMAKE_BUILD_TYPE Release)
 
add_subdirectory(easing_curves_core)
add_subdirectory(app)
