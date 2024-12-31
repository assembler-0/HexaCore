cmake_minimum_required(VERSION 3.10)
project(HexaCore VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(HexaCore src/main.cpp)
target_include_directories(HexaCore PRIVATE include)

cmake -DCMAKE_TOOLCHAIN_FILE=/workspaces/HexaCore/vcpkg/scripts/buildsystems/vcpkg.cmake ..r

