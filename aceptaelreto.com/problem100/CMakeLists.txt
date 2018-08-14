set(APP_NAME Problem100)

#Create executable
add_executable(${APP_NAME} ${APP_NAME}.cpp)

#Testing
add_test(
	${APP_NAME}_test ${CMAKE_COMMAND}
	-D TEST_EXECUTABLE=${APP_NAME}
	-D TEST_INPUT=${CMAKE_CURRENT_SOURCE_DIR}/test_in.txt
	-D TEST_OUTPUT=${CMAKE_CURRENT_SOURCE_DIR}/test_out.txt
	-P ${CMAKE_CURRENT_SOURCE_DIR}/../BlackBoxTest.cmake
) # Compares the output to reference file



set(APP_NAME Problem100_threads)

#Create executable
add_executable(${APP_NAME} ${APP_NAME}.cpp)

#Testing
add_test(
	${APP_NAME}_test ${CMAKE_COMMAND}
	-D TEST_EXECUTABLE=${APP_NAME}
	-D TEST_INPUT=${CMAKE_CURRENT_SOURCE_DIR}/test_in.txt
	-D TEST_OUTPUT=${CMAKE_CURRENT_SOURCE_DIR}/test_out.txt
	-P ${CMAKE_CURRENT_SOURCE_DIR}/../BlackBoxTest.cmake
) # Compares the output to reference file
