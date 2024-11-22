# CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(divy-c)

# Add your include and source files
include_directories(include)

# Specify the library source files
add_library(divy-c STATIC
    src/vector.c
    src/queue.c
    src/common.c
)

# Specify the install rules
install(TARGETS divy-c DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
