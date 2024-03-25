# CMake 버전 확인
cmake_minimum_required(VERSION 3.10)
# CMake 프로젝트 이름, 버전 정하기
project(hm2j VERSION 0.0.1)

# Clangd - (C/C++) IDE, 이해 안돼도 상관없음
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# src 디렉토리에서  C 파일 검색후,  SRC_FILES 변수에 저장
file(GLOB_RECURSE SRC_FILES src/*.c)
# SRC_FILES 사용해, 실행파일 생성
add_executable(${PROJECT_NAME} ${SRC_FILES})

# MySQL library libmysqlclient 검색.
find_library(MYSQL mysqlclient)
# mysqlclient를 프로젝트 실행 파일에 연결
target_link_libraries(${PROJECT_NAME} ${MYSQL})
# include 디렉토리 지정,  Link시 Header 파일 추가
# DEB : /usr/include/mysql
# macOS : /opt/homebrew/include/mysql
target_include_directories(${PROJECT_NAME}
PUBLIC "${PROJECT_SOURCE_DIR}/include"
PRIVATE "/usr/include/mysql"
PRIVATE "/opt/homebrew/include/mysql"
)

# Packaging - run `cpack`, `make package`
# Set CPack variables
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VENDOR "HM2J Team")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})

# Specify generators based on platform
if(APPLE)
  # Set the package generator to create a DMG (Disk Image) for macOS
  set(CPACK_GENERATOR "DragNDrop")
  # Set the package installation location to /Applications
  set(CPACK_PACKAGE_INSTALL_DIRECTORY "/Applications/")
elseif(UNIX AND NOT APPLE)
  # Set the package generator to create a DEB (Debian) for Linux
  set(CPACK_GENERATOR "DEB")
  # Set the package maintainer email (contact)
  set(CPACK_PACKAGE_CONTACT "kinwlsgh33@gmail.com")
endif()


# Specify the fies to be included in the package
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION .)
install(FILES README.md DESTINATION .)

# Include CPack module to enable packaging
include(CPack)