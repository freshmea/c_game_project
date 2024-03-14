cmake_minimum_required(VERSION 3.10)
project(tetrisV01)

file(GLOB SRC_FILES "src/*.c")

add_executable(tetrisV01 ${SRC_FILES})
target_include_directories(tetrisV01 PUBLIC include)

target_link_libraries(tetrisV01 ao mpg123 ncurses pthread)

install(TARGETS tetrisV01 DESTINATION /usr/local/bin)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION /usr/local/include)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/ DESTINATION /usr/local/src FILES_MATCHING PATTERN "*.c")