# c_game_project
Environment: ubuntu 22.04 (virtual machine on windows 11 - Vmware Workstation)
Programming Language: only using C language game project.
IDE: Visual Studio Code
CMake: 3.22.1
C compiler: clang
C standard: c11

## tetrisV01 설치 방법
- 순서대로 실행.
```bash
cd ~
git clone https://github.com/freshmea/c_game_project.git
cd c_game_project
mkdir build
cd build
cmake ..
make
sudo make install
```

## tetrisV01 실행 방법
```bash
tetrisV01
```

--- 
2024-03-12
---
- project start
- Doxyfile 세팅
- README.md 작성
- .gitignore 추가
- .vscode/ 추가
  - tasks.json
  - launch.json
  - settings.json
  - c_cpp_properties.json
- 참고 사이트 : 
  - https://blog.naver.com/hardinge/220515010763
- 파일 분할 하기
  - 메인 함수: tetrisV01.c
  - 화면 출력 함수: display_menu.c, display_tetris.c
  - 파일 출력 함수: result.c
  - 게임 로직 함수: update.c
  - 그림 링크 update.png
![Update Image](update.png)
![collision Image](collision.png)
  - 키 인식 함수: getch.c
- cmakefiles 작성
  - 폴내 내의 모든 소스 파일 인식 
    - file(GLOB SRC_FILES "*.c")
  - 실행 파일 인스톨 설정
    - install(TARGETS tetrisV01 DESTINATION /usr/local/bin)
  - 헤더 및 소스 파일 인스톨 설정
    - install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION /usr/local/include)
    - install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/ DESTINATION /usr/local/src FILES_MATCHING PATTERN "*.c")
  - 오브젝트 파일은 라이브러리 배포가 아니기 때문에 생략


---
2024-03-14
---
- branch 생성
  - sound 를 추가하는 작업 을 함. 
  - 쓰레드로 음악이 동작은 하는데 텍스트 출력과 scanf 의 작동이 안됨. 

- [ ] TODO: ncurses 를 사용하여 텍스트 출력을 하고 getch() 함수를 사용하여 키 입력을 받아야 함.
- [ ] TODO: sql 작동되는 branch도 만들어야 함. 

---
2024-03-16
---
- signal 함수를 60Hz 설정 함. 화면 깨지는 문제 해결
- 배경음악이 다 틀어지면 반복재생할 수 있게 만듬.


---
2024-03-25
---
- 학생들 프로젝트가 마무리 됨.
- 3개조의 프로젝트를 정리 하고 브랜치를 만들어서 정리함.
  - 