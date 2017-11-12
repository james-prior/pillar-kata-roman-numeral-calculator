include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})

set(
    TEST_SOURCES
    check_roman.c
)

add_executable(check_roman ${TEST_SOURCES})
target_link_libraries(check_roman roman ${CHECK_LIBRARIES})
