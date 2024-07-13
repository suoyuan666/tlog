set(TEST_TARGET_NAME main_test)

set (
    TEST_SRC
    main.cpp
)

set (
    TEST_INCLUDE
    ${PROJECT_SOURCE_DIR}/include/tlog
)

add_executable(${TEST_TARGET_NAME} ${TEST_SRC})
include_directories(${TEST_INCLUDE})
target_link_libraries(${TEST_TARGET_NAME} tlog)
add_test(NAME ${TEST_TARGET_NAME} COMMAND ${TEST_TARGET_NAME})