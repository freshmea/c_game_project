# HM2J_c

C + MySQL

# Table of Contents (목차)

- [Requirements (필요사항)](#Requirements)
- [Usage (사용법)](#Usage)
- [TODO (할일)](#TODO)

# Requirements

- [Git](https://git-scm.com/)  
  To clone this repo `git clone https://github.com/skoler/HM2J_c.git`

  ```bash
  sudo snap install git
  ```

- [Doxygen](https://doxygen.org/) >= 1.9.1  
  For documentation

  ```bash
  sudo apt install doxygen doxygen-gui graphviz
  brew install --cask doxygen
  ```

- [CMake](https://cmake.org) >= 3.10  
  To build this project

  ```bash
  sudo apt install cmake
  brew install cmake
  ```

- [MySQL](https://www.mysql.com/) >= 8.3.0
  To manage data by Database
  ```bash
  sudo apt install mysql-server
  sudo mysql
  ```

# Usage

## Git

### Commands (명령어)

- 깃허브 원격저장소(remote repository)를 현재컴퓨터(local)에 복사(clone) 하기

```bash
  git clone <url>
```

- 저장소 줄기(branch)들 확인하기
  - 현재 접속중인 줄기(branch)들 확인
  - 모든 줄기(branch)들 확인

```bash
  git branch
```

- 줄기(branch) 만들기

```bash
  git branch <branch>
```

- 줄기(branch) 삭제하기

  ```bash
  git branch -d <branch>
  ```

- 줄기(branch) 접속(checkout)하기

```bash
  git checkout <branch>
```

- 원격저장소 `origin`의 파일들을 현재컴퓨터에 가져와,덮어쓰기(pull) - **주의** 기존파일과 충돌(conflict)할수 있음

```bash
  git pull origin <branch>
```

- git이 관리할 파일 추가(add)하기

  ```bash
  # 하나씩 추가하기
  git add <filename>

  # 현재폴더(.)에 있는 파일 모두 추가하기
  # 이때 .gitignore 에 있는 파일들은 제외된다
  git add .
  ```

- git이 관리중이던(`--cached` 옵션) 파일을, 더 이상 관리하지 않도록 삭제(remove: `rm`)하기

  ```bash
  git rm --cached <filename>
  ```

- git이 관리중인 파일 상태(status) 확인하기

  ```bash
  git status
  ```

- git이 관리중인 파일들의 상태를, 설명(`-m` 옵션)과 함께 세이브, 저장(commit)하기

  ```bash
  git commit -m "message"
  ```

- 줄기(branch)안에 모든 세이브 파일들(commit)을, Github 원격저장소(remote repository, name: origin)에 업로드(push)하기

  ```bash
  git push origin <branch>
  ```

- feature/gotcha 줄기(branch)에, main 줄기를 합치기(merge). **방향 주의**

  ```bash
  # feature/gotcha 줄기 접속
  git checkout feature/gotcha
  # 현재줄기(feature/gotcha)에 main 줄기를 합치기
  git merge feature/gotcha
  ```

### Git으로 프로젝트 관리하기

#### Github Flow

Github가 Git으로 프로젝트를 관리하는 방법

1. main 줄기(branch)를 만들기  
   실제로 사용자에게 배포(release)하는 줄기

   - 이 줄기에 다른 줄기를 합치려면, feature 줄기에서 합친후(merge), 테스트가 되어야한다.

2. `feature/기능` 줄기(branch)를 만들기  
   새로운 기능을 추가하는 줄기

   - 새로운 기능이 필요할 때마다, 새로운 프랜치를 만든다.  
     ex: `git branch feature/gotcha`

# TODO

- [ ] Add Usage to documentation
- [ ] Add MySQL support
