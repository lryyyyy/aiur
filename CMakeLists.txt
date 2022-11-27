cmake_minimum_required(VERSION 3.14)
project(Aiur)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)

# 设置ProtoBuf路径
include_directories(${CMAKE_SOURCE_DIR}/3rdparty/protobuf-3.11.0/src)
link_directories(${CMAKE_SOURCE_DIR}/3rdparty/protobuf-3.11.0/src/.libs)

# 设置include头文件路径
include_directories(${CMAKE_SOURCE_DIR}/proto)
include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SRC
        ${CMAKE_SOURCE_DIR}/proto/*.cc
        ${CMAKE_SOURCE_DIR}/src/*.cpp
        )

add_library(aiur SHARED ${SRC})

target_link_libraries(aiur protobuf pthread)

add_executable(aiur_main ${CMAKE_SOURCE_DIR}/main.cpp)

target_link_libraries(aiur_main aiur protobuf pthread)