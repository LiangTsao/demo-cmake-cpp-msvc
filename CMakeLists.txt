cmake_minimum_required(VERSION 3.20)

# Set the project name
project(demo-cmake-cpp-msvc)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(C:/asio-1.34.2/include)
include_directories(C:/boost_1_88_0)

# Add a preprocessor definition for _WIN32_WINNT
add_definitions(-D_WIN32_WINNT=0x0601)

if(MSVC)
  add_compile_options(/utf-8)  # 强制MSVC使用UTF-8编码
endif()

if(MSVC)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug")
endif()

# Add the executable
add_executable(demo main.cpp)


