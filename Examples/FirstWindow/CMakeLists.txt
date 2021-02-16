cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(FirstWindow LANGUAGES CXX VERSION 0.0.1)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${GLEW_INCLUDE_DIRECTORIES})
include_directories(../../Renderer/include/)
link_directories(../../Renderer/build/)

add_executable(FirstWindow src/Main.cpp)
target_link_libraries(FirstWindow libsiegerenderer.a)
target_link_libraries(FirstWindow OpenGL::GL)
target_link_libraries(FirstWindow glfw)
target_link_libraries(FirstWindow ${GLEW_LIBRARIES})
