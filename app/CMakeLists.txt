cmake_minimum_required(VERSION 3.18.4)
project(app_proj)
set(CMAKE_BUILD_TYPE Release)

file(GLOB SOURCES "*.cpp")

add_executable(app ${SOURCES})

target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(app PRIVATE easing_curves_core)
