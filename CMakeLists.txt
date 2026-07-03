cmake_minimum_required(VERSION 3.10)
project(OCCT_Minimal_Example CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OCCT_INCLUDE_DIR "/usr/include/opencascade")

set(OCCT_LIBS
    TKDESTEP
    TKXSBase
    TKPrim
    TKTopAlgo
    TKG3d
    TKBRep
    TKMath
    TKernel
)

add_executable(occt_box_example main.cpp)

target_include_directories(occt_box_example PRIVATE ${OCCT_INCLUDE_DIR})

target_link_libraries(occt_box_example PRIVATE ${OCCT_LIBS})
