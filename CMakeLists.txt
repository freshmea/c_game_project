cmake_minimum_required(VERSION 3.0)
project(tetris_csk)

add_executable(tetris_csk src/main.c src/display_menu.c src/display_tetris.c)
target_include_directories(tetris_csk PUBLIC include)

install(TARGETS tetris_csk DESTINATION /usr/local/bin)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION /usr/local/include)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/ DESTINATION /usr/local/src)