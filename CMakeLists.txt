cmake_minimum_required(VERSION 3.15)
project(TestOpenCV)

find_package(OpenCV REQUIRED)

message(STATUS "OpenCV version: ${OpenCV_VERSION}")
message(STATUS "OpenCV libs: ${OpenCV_LIBS}")

add_executable(test main.cpp)

target_link_libraries(test PRIVATE ${OpenCV_LIBS})