cmake_minimum_required( VERSION 3.0 )
project( UAV )

set( CMAKE_CXX_STANDARD 17 )

# set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin )

# Testing module
add_subdirectory(thirdparty/catch2)
enable_testing()

# UAV Lib
add_subdirectory( src/matrix )

add_library( own INTERFACE )
target_include_directories( own INTERFACE include )
target_link_libraries( own INTERFACE own_matrix )

# Executables
add_executable( main src/main.cpp )
target_link_libraries( main own )
