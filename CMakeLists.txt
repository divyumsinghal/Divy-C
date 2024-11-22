# CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(divy-c)

# Add your include and source files
include_directories(include)


set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/vector.c
    ${CMAKE_SOURCE_DIR}/src/queue.c
    ${CMAKE_SOURCE_DIR}/src/stack.c
)


# Specify the library source files
add_library(divy-c STATIC ${SOURCES})

# Specify the install rules
install(TARGETS divy-c DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
