project(lista_circular_test)

add_executable(lista_circular_test
        lista_circular_test.cpp
)

target_link_libraries(
        lista_circular_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(lista_circular_test)