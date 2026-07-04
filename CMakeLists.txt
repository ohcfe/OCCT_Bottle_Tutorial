cmake_minimum_required(VERSION 3.10)
project(OCCT_Bottle_Example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(OCCT_INCLUDE_DIR "/usr/include/opencascade")

set(OCCT_LIBS
    TKDESTEP
    TKXSBase
    TKPrim
    TKTopAlgo
    TKG3d
    TKG2d
    TKBRep
    TKMath
    TKernel
    TKGeomBase
    TKFillet
    TKBO
    TKOffset
)

add_executable(occt_bottle_example main.cpp)

target_include_directories(occt_bottle_example PRIVATE ${OCCT_INCLUDE_DIR})

target_link_libraries(occt_bottle_example PRIVATE ${OCCT_LIBS})
