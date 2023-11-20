cmake_minimum_required(VERSION 3.2)
project(TEMEPAOO)   

add_subdirectory(Student)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(tema1 main.cxx)

target_link_libraries(tema1 PUBLIC Student)
target_link_libraries(tema1 PUBLIC UniStudent)
target_link_libraries(tema1 PUBLIC MasterStudent)
target_include_directories(tema1 PUBLIC
                           "${PROJECT_BINARY_DIR}")