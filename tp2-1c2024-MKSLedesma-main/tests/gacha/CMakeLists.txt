project(gacha_test)

add_executable(gacha_test
        gacha_test.cpp
)

target_link_libraries(
        gacha_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(gacha_test)