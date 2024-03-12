cmake_minimum_required(VERSION 3.10)
project(tetrisV01)

add_executable(tetrisV01 src/tetrisV01.c src/display_menu.c src/getch.c src/result.c)
target_include_directories(tetrisV01 PUBLIC include)