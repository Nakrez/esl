# Unitary test : scoped_map

enable_testing()

add_definitions(-Wall -Wextra -std=c++0x -I../../../lib)
add_executable(scoped_map scoped_map.cc)

ADD_TEST(ctest_build_scoped_map "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target scoped_map)
ADD_TEST(ctest_run_scoped_map scoped_map)
SET_TESTS_PROPERTIES (ctest_run_scoped_map PROPERTIES DEPENDS ctest_build_scoped_map)
