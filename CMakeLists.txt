cmake_minimum_required(VERSION 3.4)

project(FunWithShapesGUI)

FIND_PACKAGE(Qt5Widgets)
FIND_PACKAGE(QT5GUI)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED 1)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)

SET(MYSOURCE
    main.cpp
    box.cpp
    box.h
    cone.cpp
    cone.h
    Ellipsoid.cpp
    Ellipsoid.h
    shape.cpp
    shape.h
    xmlshapesreader.cpp
    xmlshapesreader.h
    xmlshapeswriter.cpp
    xmlshapeswriter.h
    mainwindow.ui
    mainwindow.cpp
    mainwindow.h
    shapesoutputwindow.ui
    shapesoutputwindow.h
    shapesoutputwindow.cpp
    )

add_executable(${PROJECT_NAME}
    ${MYSOURCE}
    )

target_link_libraries(${PROJECT_NAME}
    Qt5::Widgets
    Qt5::Gui
)
