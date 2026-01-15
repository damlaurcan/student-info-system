cmake_minimum_required(VERSION 3.10)

project(StudentInfoSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(student_info_system
    src/main.cpp
)

# PostgreSQL & libpqxx (Ubuntuda test ettik)
find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

target_link_libraries(student_info_system ${PQXX_LIBRARIES})
