cmake_minimum_required(VERSION 3.10)

project(paincave21)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib/glad/)
add_subdirectory(lib/glfw/)

file(GLOB pc21_source "./src/**/*.cpp")
# add the executable
add_executable(paincave21 src/main.cpp ${pc21_source})

target_link_libraries(paincave21 PRIVATE glad)
target_link_libraries(paincave21 PRIVATE glfw)
