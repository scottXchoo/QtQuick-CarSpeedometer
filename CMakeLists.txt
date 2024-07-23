cmake_minimum_required(VERSION 3.15)
project(QML_Project_Template)

set(CMAKE_CXX_STANDARD 17)

# Qt 패키지 찾기
set(CMAKE_PREFIX_PATH "/Users/chooble/Documents/Qt/6.7.2/macos/lib/cmake") # Qt 설치 경로 설정

find_package(Qt6 REQUIRED COMPONENTS Core Quick)

# Qt 모듈 설정
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# 소스 파일 추가
add_executable(QML_Project_Template
	src/main.cpp
	qml.qrc
)

# Qt 라이브러리 링크
target_link_libraries(QML_Project_Template Qt6::Core Qt6::Quick)
