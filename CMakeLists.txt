cmake_minimum_required(VERSION 3.27)

project(Journal)

if (CMAKE_GENERATOR STREQUAL "Visual Studio 16 2019")
    message("-- MSVC Qt Path Set!")
    set(CMAKE_PREFIX_PATH "C:/devel/sdk/qt6/6.6.2/msvc2019_64/lib/cmake/Qt6")
elseif(UNIX)
    message("-- Linux Qt Path Set!")
    set(CMAKE_PREFIX_PATH "/usr/lib64/cmake/Qt6")
endif()

# Set the location of the Qt6 cmake files


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find Qt6 components
find_package(Qt6 COMPONENTS Widgets REQUIRED)

include_directories(include)

add_subdirectory(source)
