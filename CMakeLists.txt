cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ncurses_tutorial)

file(GLOB SRC "lessons/*.cpp")

# find_path(NCURSES_HEADERS ncurses.h)
find_library(NCURSES_LIB ncursesw)

foreach(src_ ${SRC})
    get_filename_component(name_ ${src_} NAME_WE)
    add_executable(${name_} ${src_})
    target_link_libraries(${name_} ${NCURSES_LIB})
endforeach()
