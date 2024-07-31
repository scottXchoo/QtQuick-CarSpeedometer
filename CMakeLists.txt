cmake_minimum_required(VERSION 3.15)
project(Tesla_Speedometer)

set(CMAKE_CXX_STANDARD 23)

# Qt 패키지 찾기
set(CMAKE_PREFIX_PATH "/Users/chooble/Documents/Qt/6.7.2/macos/lib/cmake") # Qt 설치 경로 설정
find_package(Qt6 REQUIRED COMPONENTS Core Quick)

# RibbonUI 라이브러리 추가
add_subdirectory(RibbonUI) # RibbonUI's path in your project file system

# Qt 모듈 설정
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/RibbonUI/lib_source)

# 소스 파일 추가
add_executable(Tesla_Speedometer
	src/main.cpp
	qml.qrc
	src/Engine.cpp
	include/Engine.h
	src/Indicator.cpp
	include/Indicator.h
	include/constants.h
	src/CarModel.cpp
	include/CarModel.h
)

# QML 모듈 경로 설정
#set(QML_IMPORT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/RibbonUI)
#set_target_properties(Tesla_Speedometer PROPERTIES
#	QML_IMPORT_PATH "${QML_IMPORT_PATH}"
#)

# QML 모듈 경로 설정
set(QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/RibbonUI/lib_sources/qml")
set(CMAKE_QML2_IMPORT_PATH "${QML_IMPORT_PATH}")

# Qt 라이브러리 링크
target_link_libraries(Tesla_Speedometer Qt6::Core Qt6::Quick RibbonUI)
