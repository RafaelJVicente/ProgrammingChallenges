### Checking the 3 arguments: ###
# 1. TEST_EXECUTABLE is the command to run with all its arguments
if( NOT TEST_EXECUTABLE )
   message( FATAL_ERROR "Variable TEST_EXECUTABLE not defined" )
endif( NOT TEST_EXECUTABLE )

# 2. TEST_INPUT is the file input for stdin
if( NOT TEST_INPUT )
   message( FATAL_ERROR "Variable TEST_INPUT not defined" )
endif( NOT TEST_INPUT )

# 3. TEST_OUTPUT is the file containing the correct output
if( NOT TEST_OUTPUT )
   message( FATAL_ERROR "Variable TEST_OUTPUT not defined" )
endif( NOT TEST_OUTPUT )

### Make the process: ###
set(TMP_FILE test_temp.txt)

# Generate test.temp as output of the program
execute_process(
   COMMAND ${TEST_EXECUTABLE} ${TEST_OUTPUT}
   INPUT_FILE ${TEST_INPUT}
   OUTPUT_FILE ${TMP_FILE}
)

# Compare test.temp with correct output file
execute_process(
   COMMAND ${CMAKE_COMMAND} -E compare_files ${TMP_FILE} ${TEST_OUTPUT}
   RESULT_VARIABLE TEST_FAILED
)

# Send error message and error output
if( TEST_FAILED )
   message( FATAL_ERROR "The execution output does not match with given file: \"${CMAKE_CURRENT_BINARY_DIR}/${TMP_FILE}\"" )
endif( TEST_FAILED )

# Remove temporal file if the files are equals
execute_process(
   COMMAND ${CMAKE_COMMAND} -E remove ${TMP_FILE}
)
