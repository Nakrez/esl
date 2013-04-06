# Unitary test : lib/misc/stack

enable_testing()

add_definitions(-Wall -Wextra -std=c++0x -I../../../lib)
add_executable(stack
               EXCLUDE_FROM_ALL
               stack.cc)

ADD_TEST(ctest_build_stack "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target stack)
ADD_TEST(ctest_run_stack stack)
