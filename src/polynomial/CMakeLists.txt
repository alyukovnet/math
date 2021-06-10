cmake_minimum_required( VERSION 3.0 )
project( own_polynomial )

set( CMAKE_CXX_STANDARD 17 )

set( SOURCES src/polynomial.cpp src/binomial.cpp )
set( HEADERS include/own/polynomial.h include/own/binomial.h )

add_library( own_polynomial ${SOURCES} ${HEADERS} )
target_include_directories( own_polynomial PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )
