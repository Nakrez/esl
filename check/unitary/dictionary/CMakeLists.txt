# Unitary test : lib/misc/dictionary

enable_testing()

add_definitions(-Wall -Wextra -std=c++0x -I../../../lib)
add_executable(dictionary
               EXCLUDE_FROM_ALL
               dictionary.cc)

ADD_TEST(ctest_build_dictionary "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target dictionary)
ADD_TEST(ctest_run_dictionary dictionary)
