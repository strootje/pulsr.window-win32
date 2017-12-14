# project setup
cmake_minimum_required(VERSION 3.9)
project(Pulsr.Drawing VERSION 1.0.0 LANGUAGES CXX)
set(TARGET_NAME ${PROJECT_NAME})

# use modern cxx
set(CMAKE_CXX_STANDARD 14)
set(CXX_STANDARD TRUE)

# unit testing
include(GoogleTest)
enable_testing()

# conan scripts
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# user options
option(BUILD_TESTS "Build Unit Tests (requires googletest)" OFF)

# define folder setup
set(DIR_BASE ${CMAKE_CURRENT_SOURCE_DIR})
set(DIR_INCLUDE ${DIR_BASE}/include)
set(DIR_SRC ${DIR_BASE}/src)
set(DIR_TESTS ${DIR_BASE}/tests)

# add subdirs
add_subdirectory(${DIR_SRC})
add_subdirectory(${DIR_TESTS})
