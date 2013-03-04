##########################
#      STACK MODULE      #
##########################

add_definitions(-Wall -Wextra -std=c++0x -I../../src -I../../lib -g)

ADD_LIBRARY(stack_module SHARED
            stack.cc
            stack-object.cc
            stack-module.cc)

# Setup correct name <stack.eslm>
set_target_properties(stack_module PROPERTIES 
                      PREFIX ""
                      OUTPUT_NAME "stack"
                      SUFFIX ".eslm"
                      LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

INSTALL(TARGETS stack_module
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
