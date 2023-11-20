add_library(Student STATIC Student.cpp)
target_include_directories(Student INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
add_library(UniStudent STATIC UniStudent.cpp)
add_library(MasterStudent STATIC MasterStudent.cpp)

