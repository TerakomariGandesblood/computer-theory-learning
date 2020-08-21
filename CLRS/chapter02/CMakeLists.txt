add_executable(insertion-sort test.cpp main.cpp)
target_link_libraries(insertion-sort ${GTEST_LIBRARIES})
gtest_discover_tests(insertion-sort)
