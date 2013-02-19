##########################
#       ESL MODULE       #
##########################

ADD_LIBRARY(esl_module SHARED
            esl.cc)

# Setup correct name <esl.eslm>
set_target_properties(esl_module PROPERTIES 
                      PREFIX ""
                      OUTPUT_NAME "esl"
                      SUFFIX ".eslm"
                      LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

INSTALL(TARGETS esl_module
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
