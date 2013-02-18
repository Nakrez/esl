cmake_minimum_required(VERSION 2.8)

project(esl)

find_package(BISON)
find_package(FLEX)

add_definitions(-Wall -Werror -std=c++0x)

ADD_LIBRARY(esl_lib SHARED
            lib/context.cc
            lib/exception.cc)

add_executable(esl
               src/compile/compiler.cc
               src/main.cc)
add_dependencies(esl parser)
