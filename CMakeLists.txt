cmake_minimum_required(VERSION 3.20)

# Set the project name
project(demo-cmake-cpp-msvc)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the compiler to clang clang++.exe
set(CMAKE_C_COMPILER "clang.exe")
set(CMAKE_CXX_COMPILER "clang++.exe")

# Add include directories
include_directories(C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.43.34808/include)
include_directories(C:/Users/liang/Desktop/gitee/asio/asio/include)

# Add a preprocessor definition for _WIN32_WINNT
add_definitions(-D_WIN32_WINNT=0x0601)

# Set the build type
set(CMAKE_BUILD_TYPE Debug)

# Add the executable
add_executable(demo main.cpp)


