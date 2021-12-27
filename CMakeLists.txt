cmake_minimum_required(VERSION 3.10)

project(paincave21)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib/glad/)
add_subdirectory(lib/glfw/)

# add the executable
add_executable(paincave21 src/main.cpp)

target_link_libraries(paincave21 PRIVATE glad)
target_link_libraries(paincave21 PRIVATE glfw)
