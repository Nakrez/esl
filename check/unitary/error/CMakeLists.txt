# Unitary test : lib/misc/error

enable_testing()

add_definitions(-Wall -Wextra -std=c++0x -I../../../lib)
add_executable(error
               EXCLUDE_FROM_ALL
               ../../../lib/misc/error.cc
               error.cc)

ADD_TEST(ctest_build_error "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target error)
ADD_TEST(ctest_run_error error)
