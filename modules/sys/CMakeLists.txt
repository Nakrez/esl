##########################
#      SYS MODULE        #
##########################

add_definitions(-Wall -Wextra -std=c++0x -I../../src -I../../lib -g)

ADD_LIBRARY(sys_module SHARED
            sys.cc)

# Setup correct name <sys.eslm>
set_target_properties(sys_module PROPERTIES 
                      PREFIX ""
                      OUTPUT_NAME "sys"
                      SUFFIX ".eslm"
                      LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

INSTALL(TARGETS sys_module
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
