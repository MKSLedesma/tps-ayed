project(cola_test)

add_executable(cola_test
        cola_test.cpp
)

target_link_libraries(
        cola_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(cola_test)