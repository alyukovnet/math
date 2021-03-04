cmake_minimum_required( VERSION 3.0 )
project( own_matrix )

set( CMAKE_CXX_STANDARD 17 )

set( SOURCES src/complex.cpp src/matrix.cpp )
set( HEADERS include/own/complex.h include/own/matrix.h )

add_library( own_matrix ${SOURCES} ${HEADERS} )
target_include_directories( own_matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )

# Testing
add_executable(test_complex test/test_complex.cpp)
target_link_libraries(test_complex PUBLIC catch2 own)
add_test(NAME test_complex COMMAND test_complex)
