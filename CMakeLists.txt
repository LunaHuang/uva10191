cmake_minimum_required(VERSION 3.0.0)
project(uva10954 VERSION 0.1.0)

include(CTest)
enable_testing()
find_package(Boost 1.55.0 COMPONENTS filesystem system REQUIRED)
option(WITH_GTEST "Enable Google Test" ON)

if(WITH_GTEST)
  find_package(GTest CONFIG REQUIRED)
  MESSAGE("Enable Google Test")
  ADD_DEFINITIONS("-DWITH_GTEST")
endif()

if(WITH_GTEST)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/case5
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/case6
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
add_executable(uva10954_unitest test.cpp)
target_link_libraries(uva10954_unitest GTest::gtest)
else()
add_executable(uva10954 main.cpp)
endif()

