##########################
#       IO MODULE        #
##########################

ADD_LIBRARY(io_module SHARED
            file.cc
            file-object.cc
            io.cc)

# Setup correct name <io.eslm>
set_target_properties(io_module PROPERTIES 
                      PREFIX ""
                      OUTPUT_NAME "io"
                      SUFFIX ".eslm"
                      LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
