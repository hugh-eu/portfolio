cmake_minimum_required(VERSION 2.8)
project(carplate)
add_executable(carplate recognizer.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(carplate ${OpenCV_LIBS})

target_link_libraries(carplate -llept -ltesseract)

include_directories("/usr/include/mariadb")
target_link_libraries(carplate "mysqlclient")