cmake_minimum_required(VERSION 3.9)
project(SharadTermOx)

add_subdirectory(external/TermOx)
add_executable(sharad src/main.cpp)
target_link_libraries(sharad PRIVATE TermOx)
