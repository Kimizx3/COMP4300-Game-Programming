cmake_minimum_required(VERSION 3.28)
project(COMP4300)

set(CMAKE_CXX_STANDARD 17)

set(main main.cpp)
add_executable(main main.cpp)

find_package(SFML 2.6.1 COMPONENTS system window graphics network audio REQUIRED)

include_directories(C:/SFML-2.6.1)
target_link_libraries(main sfml-system sfml-window sfml-graphics sfml-network sfml-audio)