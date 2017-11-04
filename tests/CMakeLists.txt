
set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_target(${TARGET_NAME}Tests ALL DEPENDS ${TARGET_NAME})
# add_subdirectory(${BASE_DIR}/LoggerTests)
# add_subdirectory(${BASE_DIR}/StreamWriterTests)
