cmake_minimum_required(VERSION 3.15)
project(SDRSatelliteReceiver VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -O3 -march=native)
elseif(MSVC)
    add_compile_options(/W4 /O2)
endif()

add_library(sdr_core
    src/BinaryFileSource.cpp
)

target_include_directories(sdr_core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_executable(sdr_app src/main.cpp)
target_link_libraries(sdr_app PRIVATE sdr_core)