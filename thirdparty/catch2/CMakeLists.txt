project(Catch2 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# Header only library, therefore INTERFACE
add_library(catch2 INTERFACE)

# INTERFACE targets only have INTERFACE properties
target_include_directories(catch2 INTERFACE include)
