cmake_minimum_required(VERSION 3.1.0)
project(Pulsr.Window VERSION 0.1.0 LANGUAGES CXX)


set(DIR_BASE ${CMAKE_CURRENT_SOURCE_DIR})
set(DIR_INCLUDE ${DIR_BASE}/include)
set(DIR_SOURCES ${DIR_BASE}/src)
set(DIR_TESTS ${DIR_BASE}/tests)

set(TARGET_NAME ${PROJECT_NAME})
set(TARGET_COMPILER_FLAGS "")
set(TARGET_LINKED_FLAGS "")
set(TARGET_SOURCES
	${DIR_SOURCES}/Manager.cpp
	${DIR_SOURCES}/Window.cpp)
set(TARGET_DEPS Grawlog Pulsr.Core)


if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set(TARGET_COMPILER_FLAGS "${TARGET_COMPILER_FLAGS} /std:c++latest")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	set(TARGET_COMPILER_FLAGS "${TARGET_COMPILER_FLAGS} -std=c++0z")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set(TARGET_COMPILER_FLAGS "${TARGET_COMPILER_FLAGS} -std=gnu++1z")
else()
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TARGET_COMPILER_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${TARGET_LINKED_FLAGS}")


add_library(${TARGET_NAME} ${TARGET_SOURCES})
target_include_directories(${TARGET_NAME} PRIVATE ${DIR_INCLUDE})

target_link_libraries(${TARGET_NAME} $ENV{local}/bin/libGrawlog.dll $ENV{local}/bin/libPulsr.Core.dll)
target_include_directories(${TARGET_NAME} PUBLIC $ENV{local}/include)

install(TARGETS ${TARGET_NAME} EXPORT ${TARGET_NAME}Targets
	RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
	LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
	ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(DIRECTORY ${DIR_INCLUDE}/
	DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME} COMPONENT Devel)

if(WIN32 AND MSVC)
	set_target_properties(${TARGET_NAME} PROPERTIES COMPILE_FLAGS "-wd4005")
endif()

# if(${BUILD_SPECS} OR ${BUILD_TESTS})
# 	enable_testing()
# 	add_subdirectory(${DIR_SPECS})
# 	add_subdirectory(${DIR_TESTS})
# endif()

if(COMMAND setup_solution)
	setup_solution(${PROJECT_NAME} ${TARGET_NAME} "${TARGET_DEPS}")
else()
	foreach(TARGET_DEP ${TARGET_DEPS})
		find_package(${TARGET_DEP} REQUIRED)
	endforeach()
endif()
