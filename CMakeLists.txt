cmake_minimum_required(VERSION 3.10)

project(StudentInfoSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(student_info_system
    src/main.cpp
)
