##########################
#      SYS MODULE        #
##########################

ADD_LIBRARY(sys_module SHARED
            sys.cc)

# Setup correct name <sys.eslm>
set_target_properties(sys_module PROPERTIES 
                      PREFIX ""
                      OUTPUT_NAME "sys"
                      SUFFIX ".eslm"
                      LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
