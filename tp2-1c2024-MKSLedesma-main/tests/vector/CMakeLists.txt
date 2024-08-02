project(vector_test)

add_executable(vector_test
        vector_test.cpp
)

target_link_libraries(
        vector_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(vector_test)