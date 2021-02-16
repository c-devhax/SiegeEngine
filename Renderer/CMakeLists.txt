cmake_minimum_required(VERSION 3.17)
project(Siege_Renderer LANGUAGES CXX VERSION 0.0.0.1)

include_directories(include)

file(GLOB source_files "src/*.cpp")
add_library(Siege_Renderer STATIC ${source_files})
