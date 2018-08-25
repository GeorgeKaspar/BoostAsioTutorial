cmake_minimum_required(VERSION 3.5.1)
add_executable(kaspar main.cpp)
target_link_libraries(kaspar boost_system boost_thread pthread gtest boost_program_options)