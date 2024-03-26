cmake_minimum_required(VERSION 3.0)
project(findPicture)

file(GLOB SRC_FILES "src/*.c")

find_library(MYSQL mysqlclient)
add_executable(findPicture ${SRC_FILES})
target_include_directories(findPicture PUBLIC include /usr/include/mysql)
target_link_libraries(findPicture ${MYSQL} )


install(TARGETS findPicture DESTINATION /usr/local/bin)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION /usr/local/include)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/ DESTINATION /usr/local/src)

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "csk")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "findPicture")
include(CPack)