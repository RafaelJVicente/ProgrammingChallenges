project(ProgramingChallenges)
cmake_minimum_required(VERSION 3.2)

##### Compiler #####
set(CMAKE_CXX_STANDARD 14)

##### Testing #####
enable_testing()

##### Apps #####
# Headers
include_directories(${PROJECT_SOURCE_DIR})

# Libraries
add_subdirectory (aceptaelreto.com)