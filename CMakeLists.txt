cmake_minimum_required(VERSION 3.0)
project(snake_mbg)

file(GLOB SRC_FILES "src/*.c")

#find_library(MYSQL mysqlclient)
# add the executable
add_executable(snake_mbg ${SRC_FILES})
target_include_directories(snake_mbg PUBLIC include) #PUBLIC /usr/include/mysql
target_link_libraries(snake_mbg ${MYSQL} )



install(TARGETS snake_mbg DESTINATION /usr/local/bin)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION /usr/local/include)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/ DESTINATION /usr/local/src)

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "mbg")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Snake game")
include(CPack)