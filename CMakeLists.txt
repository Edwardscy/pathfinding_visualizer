cmake_minimum_required(VERSION 3.5)
project(pathfinding_visualizer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)


include_directories(include)
#include_directories(src)
include_directories(ui)

#aux_source_directory(include include)
#aux_source_directory(src src)

set(INCLUDE
        include/mainwindow.h
        include/map_graphic_widget.h
        include/grip_map.h
        include/grid.h
        include/parse_data.h)


set(SOURCE
        src/mainwindow.cpp
        src/map_graphic_widget.cpp
        src/grip_map.cpp
        src/grip.cpp
        src/parse_data.cpp)

set(CMAKE_AUTOUIC_SEARCH_PATHS ui)
qt5_wrap_ui(UI_HEADERS
        ui/main_widget.ui
        ui/main_widget.h
        )

add_executable(pathfinding_visualizer
        main.cpp

        ${INCLUDE}
        ${SOURCE}
        ${UI_HEADERS}
#        src/mainwindow.cpp
#        include/mainwindow.h
        )


target_link_libraries(pathfinding_visualizer
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

