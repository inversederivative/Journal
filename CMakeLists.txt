cmake_minimum_required(VERSION 3.27)

project(JournalQt)

# Copy image files to the build directory
file(COPY ${CMAKE_SOURCE_DIR}/images DESTINATION ${CMAKE_BINARY_DIR}/bin/Debug)
message("Images Copied to Binary Directory!")

# Set the location of the Qt6 cmake files
set(CMAKE_PREFIX_PATH "C:/devel/sdk/qt6/6.6.2/msvc2019_64/lib/cmake/Qt6")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find Qt6 components
find_package(Qt6 COMPONENTS Widgets REQUIRED)

include_directories(include)

add_subdirectory(source)
