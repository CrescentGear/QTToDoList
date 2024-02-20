cmake_minimum_required(VERSION 3.15)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

project(QtToDoList)

# set the project name
string(REGEX REPLACE "(.+)\\CMakeLists.txt" "\\1" PROJECT_INIT_PATH ${PROJECT_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_INIT_PATH}/bin)
set(QT_PATH "C:/Qt/5.15.2/msvc2019_64")
set(CMAKE_PREFIX_PATH ${QT_PATH}/lib/cmake)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakePredefinedTargets")

set (dependenceFile
${CMAKE_CURRENT_SOURCE_DIR}/dll
${CMAKE_CURRENT_SOURCE_DIR}/res
)

execute_process( COMMAND ${CMAKE_COMMAND} -E copy_directory ${dependenceFile} ${EXECUTABLE_OUTPUT_PATH}/Debug)
execute_process( COMMAND ${CMAKE_COMMAND} -E copy_directory ${dependenceFile} ${EXECUTABLE_OUTPUT_PATH}/Release)

find_package(Qt5 COMPONENTS Widgets Core Sql Gui REQUIRED )
# include_directories(${QT_PATH}/include)
include_directories(${PROJECT_SOURCE_DIR}/inc)

file(GLOB_RECURSE res res/*.*)
file(GLOB_RECURSE src src/*.cpp)
file(GLOB_RECURSE inc inc/*.h)

add_executable( ${PROJECT_NAME} WIN32
${src}
${inc}
${res}
)

target_link_libraries(${PROJECT_NAME} 
 Qt5::Widgets
 Qt5::Core
 Qt5::Sql
 Qt5::Gui)
  