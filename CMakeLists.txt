cmake_minimum_required(VERSION 3.10)
project(tetrisV01)

file(GLOB SRC_FILES "src/*.c")

add_executable(tetrisV01 ${SRC_FILES})
target_include_directories(tetrisV01 PUBLIC include)

target_link_libraries(tetrisV01 ao mpg123 ncurses pthread)

install(TARGETS tetrisV01 DESTINATION /usr/local/bin)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION /usr/local/include/tetris)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/ DESTINATION /usr/local/src/tetris FILES_MATCHING PATTERN "*.c")

set(CPACK_PACKAGE_NAME "tetrisV01")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "choisgil") # replace with your name
set(CPACK_PACKAGE_DESCRIPTION "A Tetris game") # replace with your description
set(CPACK_GENERATOR "DEB")
include(CPack)
