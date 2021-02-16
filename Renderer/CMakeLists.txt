cmake_minimum_required(VERSION 3.17)
project(siegerenderer LANGUAGES CXX VERSION 0.0.0.1)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)

include_directories(${GLEW_INCLUDE_DIRS})
include_directories(include)

file(GLOB source_files "src/*.cpp")
add_library(siegerenderer STATIC ${source_files})

target_link_libraries(siegerenderer OpenGL::GL)
target_link_libraries(siegerenderer glfw)
target_link_libraries(siegerenderer ${GLEW_LIBRARIES})
