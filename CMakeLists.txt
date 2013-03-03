cmake_minimum_required(VERSION 2.8)

project(esl)

FIND_PROGRAM(BISON_EXECUTABLE NAMES bison bison.exe )

IF(BISON_EXECUTABLE)
     SET(BISON_FOUND TRUE)

     EXECUTE_PROCESS(COMMAND ${BISON_EXECUTABLE} --version
         OUTPUT_VARIABLE _BISON_VERSION
     )
     string (REGEX MATCH "[0-9]+\\.[0-9]+\\.[0-9]+" BISON_VERSION 
"${_BISON_VERSION}")
ENDIF(BISON_EXECUTABLE)

IF(BISON_FOUND)
   IF(NOT Bison_FIND_QUIETLY)
     MESSAGE(STATUS "Found Bison: ${BISON_EXECUTABLE}")
   ENDIF(NOT Bison_FIND_QUIETLY)
ELSE(BISON_FOUND)
   IF(Bison_FIND_REQUIRED)
     MESSAGE(FATAL_ERROR "Could not find Bison")
   ENDIF(Bison_FIND_REQUIRED)
ENDIF(BISON_FOUND)

FIND_PROGRAM(FLEX_EXECUTABLE NAMES flex flex.exe )

IF(FLEX_EXECUTABLE)
     SET(FLEX_FOUND TRUE)

     EXECUTE_PROCESS(COMMAND ${FLEX_EXECUTABLE} --version
         OUTPUT_VARIABLE _FLEX_VERSION
     )
     string (REGEX MATCH "[0-9]+\\.[0-9]+\\.[0-9]+" FLEX_VERSION
"${_FLEX_VERSION}")
ENDIF(FLEX_EXECUTABLE)

IF(FLEX_FOUND)
   IF(NOT Flex_FIND_QUIETLY)
     MESSAGE(STATUS "Found Flex: ${FLEX_EXECUTABLE}")
   ENDIF(NOT Flex_FIND_QUIETLY)
ELSE(FLEX_FOUND)
   IF(Flex_FIND_REQUIRED)
     MESSAGE(FATAL_ERROR "Could not find Flex")
   ENDIF(Flex_FIND_REQUIRED)
ENDIF(FLEX_FOUND)

add_definitions(-Wall -Wextra -std=c++0x -Isrc -Ilib)

#######################
#######################
####### ESL LIB #######
#######################
#######################

ADD_LIBRARY(esl_lib SHARED
            lib/context.cc
            lib/exception.cc
            lib/extension.cc
            lib/function.cc
            lib/module.cc
            lib/params.cc
            lib/stack-delimiter.cc
            lib/type/array.cc
            lib/type/array-object.cc
            lib/type/int.cc
            lib/type/int-object.cc
            lib/type/string.cc
            lib/type/string-object.cc
            lib/type/object.cc
            lib/type/type.cc
            lib/type/squeleton.cc
            lib/misc/symbol.cc
            lib/misc/indent.cc
            src/execute/vm.cc)

SET_TARGET_PROPERTIES(
    esl_lib
    PROPERTIES
    VERSION 1.0.0
    OUTPUT_NAME esl
)

target_link_libraries(esl_lib dl)

#######################
#######################
####### ESL BIN #######
#######################
#######################

##########################
#         BISON          #
##########################

SET(src_parser "${CMAKE_CURRENT_SOURCE_DIR}/src/parser/parser.yy")
SET(dst_parser "${CMAKE_CURRENT_SOURCE_DIR}/src/parser/parser.cc")

ADD_CUSTOM_COMMAND(
        OUTPUT "${dst_parser}"
        DEPENDS "${src_parser}"
        COMMAND
        ${BISON_EXECUTABLE} -o${dst_parser} ${src_parser}
        )

add_custom_target(esl_grammar DEPENDS "${dst_parser}")

##########################
#          FLEX          #
##########################

SET(src_lexer "${CMAKE_CURRENT_SOURCE_DIR}/src/parser/lexer.ll")
SET(dst_lexer "${CMAKE_CURRENT_SOURCE_DIR}/src/parser/lexer.cc")

ADD_CUSTOM_COMMAND(
        OUTPUT "${dst_lexer}"
        DEPENDS "${src_lexer}"
        COMMAND
        ${FLEX_EXECUTABLE} -o${dst_lexer} ${src_lexer}
        )

add_custom_target(esl_lexer DEPENDS "${dst_lexer}")

add_executable(esl
               src/parser/parser.cc
               src/parser/lexer.cc
               src/parser/driver.cc
               src/utils/bytecode.cc
               src/utils/ro-data.cc
               src/utils/utils.cc
               src/ast/ast.cc

               src/ast/dec.cc
               src/ast/attribut-dec.cc
               src/ast/function-dec.cc
               src/ast/import-dec.cc
               src/ast/method-dec.cc
               src/ast/var-dec.cc

               src/ast/exp.cc
               src/ast/int-exp.cc
               src/ast/op-exp.cc
               src/ast/function-call-exp.cc
               src/ast/string-exp.cc
               src/ast/return-exp.cc
               src/ast/break-exp.cc
               src/ast/continue-exp.cc
               src/ast/new-exp.cc
               src/ast/assign-exp.cc

               src/ast/instr.cc
               src/ast/if-instr.cc
               src/ast/else-instr.cc
               src/ast/while-instr.cc

               src/ast/var.cc
               src/ast/attribut-var.cc
               src/ast/var-id.cc
               src/ast/method-call-var.cc
               src/ast/module-call-var.cc
               src/ast/module-attribut-var.cc

               src/ast/pretty-printer.cc
               src/ast/visitor.cc
               #src/compile/compiler.cc
               src/main.cc)

# Library link

target_link_libraries(esl esl_lib)
TARGET_LINK_LIBRARIES(esl LINK_INTERFACE_LIBRARIES)

# ESL dependencies

add_dependencies(esl esl_grammar)
add_dependencies(esl esl_lexer)
add_dependencies(esl esl_lib)

LIST(APPEND extra_clean_files
     src/parser/parser.hh
     src/parser/location.hh
     src/parser/position.hh
     src/parser/stack.hh
)

SET_DIRECTORY_PROPERTIES(PROPERTIES
                         ADDITIONAL_MAKE_CLEAN_FILES
                         "${extra_clean_files}")


#######################
#######################
##### ESL MODULES #####
#######################
#######################

add_subdirectory(modules)

#######################
#######################
#####  ESL TEST   #####
#######################
#######################

ENABLE_TESTING()

SET(TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/check")
ADD_TEST("AST" ${TEST_DIR}/ast/ast_check.sh)
ADD_TEST("Arith" ${TEST_DIR}/arith/arith_check.sh)
ADD_TEST("Array" ${TEST_DIR}/array/array_check.sh)
ADD_TEST("Comment" ${TEST_DIR}/comment/comment_check.sh)
ADD_TEST("Control" ${TEST_DIR}/control/control_check.sh)
ADD_TEST("DataStructure" ${TEST_DIR}/datastruct/datastruct_check.sh)
ADD_TEST("ESLModule" ${TEST_DIR}/esl/esl_check.sh)
ADD_TEST("Function" ${TEST_DIR}/functions/functions_check.sh)
ADD_TEST("Integer" ${TEST_DIR}/int/int_check.sh)
ADD_TEST("IOModule" ${TEST_DIR}/io/io_check.sh)
ADD_TEST("Loops" ${TEST_DIR}/loops/loops_check.sh)
ADD_TEST("Mix" ${TEST_DIR}/mix/mix_check.sh)
ADD_TEST("ObjectParadigm" ${TEST_DIR}/oo/oo_check.sh)
ADD_TEST("String" ${TEST_DIR}/strings/strings_check.sh)
ADD_TEST("SysModule" ${TEST_DIR}/sys/sys_check.sh)

#######################
#######################
###  INSTALL RULE   ###
#######################
#######################

INSTALL(PROGRAMS esl DESTINATION bin)
INSTALL(TARGETS esl_lib
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

#######################
#######################
##  UNINSTALL RULE   ##
#######################
#######################

CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)
ADD_CUSTOM_TARGET(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake/cmake_uninstall.cmake")


#######################
#######################
##    CLEAR RULE     ##
#######################
#######################

CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_clear.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/cmake_clear.cmake"
  IMMEDIATE @ONLY)
ADD_CUSTOM_TARGET(clear
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake/cmake_clear.cmake")
