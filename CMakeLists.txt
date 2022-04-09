cmake_minimum_required(VERSION 3.0.0)
project(uva10191 VERSION 0.1.0)

include(CTest)
enable_testing()
find_package(Boost 1.55.0 COMPONENTS filesystem system REQUIRED)
option(WITH_GTEST "Enable Google Test" OFF)

if(WITH_GTEST)
  find_package(GTest CONFIG REQUIRED)
  MESSAGE("Enable Google Test")
  ADD_DEFINITIONS("-DWITH_GTEST")
endif()

if(WITH_GTEST)
add_executable(uva10191_unitest test.cpp)
target_link_libraries(uva10191_unitest GTest::gtest)
else()
add_executable(uva10191 main.cpp)
endif()

