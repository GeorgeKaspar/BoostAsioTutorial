cmake_minimum_required(VERSION 3.5.1)
include_directories(include)
add_executable(io_service_1 src/io_service_1.cpp)
target_link_libraries(io_service_1 boost_system boost_thread gtest pthread)