
# test setup
set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_target(${TARGET_NAME}Tests ALL
	DEPENDS ${TARGET_NAME}
	COMMENT "Building unit tests with Googletest")

if(NOT BUILD_TESTS)
	set_target_properties(${TARGET_NAME}Tests PROPERTIES EXCLUDE_FROM_ALL ON)
endif()

# include test projects
# add_subdirectory(${BASE_DIR/...Tests})
