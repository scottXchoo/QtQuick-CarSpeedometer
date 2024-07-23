cmake_minimum_required(VERSION 3.15)
project(Tesla_Speedometer)

set(CMAKE_CXX_STANDARD 23)

# Qt 패키지 찾기
set(CMAKE_PREFIX_PATH "/Users/chooble/Documents/Qt/6.7.2/macos/lib/cmake") # Qt 설치 경로 설정

find_package(Qt6 REQUIRED COMPONENTS Core Quick)

# Qt 모듈 설정
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# 소스 파일 추가
add_executable(Tesla_Speedometer
	src/main.cpp
	qml.qrc
	src/Car.cpp
	include/Car.h
	src/Speedometer.cpp
	include/Speedometer.h
	src/Engine.cpp
	include/Engine.h
	src/Indicator.cpp
	include/Indicator.h
)

# Qt 라이브러리 링크
target_link_libraries(Tesla_Speedometer Qt6::Core Qt6::Quick)
