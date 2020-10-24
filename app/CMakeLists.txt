cmake_minimum_required(VERSION 3.18.4)
project(app_proj)
set(CMAKE_BUILD_TYPE Release)
include(../cmake/StandardProjectSettings.cmake)
 
set ( PROJECT_LINK_LIBS libeasing_curves_core.a )
link_directories( ${BUILD_DIR}/easing_curves_core )

include_directories(. ../easing_curves_core)
 
file(GLOB SOURCES "*.cpp")
 
add_executable(app ${SOURCES})
target_link_libraries(app ${PROJECT_LINK_LIBS} )
