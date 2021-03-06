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

add_definitions(-Wall -Wextra -std=c++0x -Isrc -Ilib -g)

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
            lib/misc/visibility.cc
            lib/misc/indent.cc
            lib/misc/error.cc
            )

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
               src/parser/libparser.cc
               src/parser/command.cc

               src/utils/utils.cc
               src/utils/option.cc

               src/ast/ast.cc
               src/ast/dec.cc
               src/ast/attribut-dec.cc
               src/ast/function-dec.cc
               src/ast/method-dec.cc
               src/ast/var-dec.cc
               src/ast/class-dec.cc
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
               src/ast/import-instr.cc
               src/ast/var.cc
               src/ast/attribut-var.cc
               src/ast/var-id.cc
               src/ast/method-call-var.cc
               src/ast/module-call-var.cc
               src/ast/module-attribut-var.cc
               src/ast/array-var.cc
               src/ast/pretty-printer.cc
               src/ast/libast.cc
               src/ast/command.cc

               src/bytecode/bytecode.cc
               src/bytecode/pop.cc
               src/bytecode/operation.cc
               src/bytecode/bracket-op.cc
               src/bytecode/new-object.cc
               src/bytecode/store-var.cc
               src/bytecode/store-attr.cc
               src/bytecode/store-array.cc
               src/bytecode/store-local.cc
               src/bytecode/load-var.cc
               src/bytecode/load-local.cc
               src/bytecode/load-str.cc
               src/bytecode/load-int.cc
               src/bytecode/load-float.cc
               src/bytecode/load-attr.cc
               src/bytecode/load-module.cc
               src/bytecode/open-module.cc
               src/bytecode/call-module.cc
               src/bytecode/call-method.cc
               src/bytecode/call-function.cc
               src/bytecode/start-class.cc
               src/bytecode/end-class.cc
               src/bytecode/register-attribut.cc
               src/bytecode/register-function.cc
               src/bytecode/inherit.cc
               src/bytecode/jump.cc
               src/bytecode/jump-true.cc
               src/bytecode/jump-false.cc
               src/bytecode/return.cc
               src/bytecode/delim.cc
               src/bytecode/visitor.cc
               src/bytecode/bytecode-dumper.cc

               src/compile/compiler.cc
               src/compile/libcompile.cc
               src/compile/command.cc

               src/command/command.cc
               src/command/callback-command.cc
               src/command/register.cc

               src/execute/vm.cc
               src/execute/executable.cc
               src/execute/executable-dumper.cc
               src/execute/command.cc
               src/execute/libexecute.cc

               src/other/command.cc

               src/global.cc
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


SET(TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/check")


ENABLE_TESTING()

add_subdirectory(${TEST_DIR}/unitary)

ADD_TEST("AST" ${TEST_DIR}/ast/ast_check.sh)
ADD_TEST("Bytecode" ${TEST_DIR}/bytecode/bytecode_check.sh)
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
ADD_CUSTOM_TARGET(distclean
  COMMAND ${CMAKE_BUILD_TOOL} clean
  COMMAND "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake/cmake_clear.cmake")
