cmake_minimum_required(VERSION 3.10)
project(OCCT_Minimal_Example C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Freetype REQUIRED)
find_package(MPI REQUIRED)

find_package(VTK REQUIRED COMPONENTS CommonCore IOImage)

find_package(OpenCASCADE CONFIG REQUIRED)

add_executable(occt_box_example main.cpp)

target_include_directories(occt_box_example PRIVATE ${OpenCASCADE_INCLUDE_DIRS})

target_link_libraries(occt_box_example PRIVATE ${OpenCASCADE_LIBRARIES})
