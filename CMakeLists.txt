cmake_minimum_required(VERSION 3.6)

project(game LANGUAGES CXX) # имя проекта и язык используемый в проекте (c++)

set(CMAKE_CXX_STANDARD 17) # стандарт с++ 2017
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall -Werror -Wextra -Wzero-as-null-pointer-constant -Winit-self -Wswitch-default -Wfloat-equal -Wno-unused-parameter -fPIC -march=native")
set(CMAKE_CXX_FLAGS_RELEASE "-O3") # включаем оптимизаци компилятора

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")  # добавляем дебажные символы в бинарный файл для дебага

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake") # добавляем дополнительные модули CMake

# Подключаем библиотеку bear-lib-terminal
find_package(BearLibTerminal REQUIRED)
include_directories(SYSTEM ${BLT_INCLUDE_DIRS})


set(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.cpp)

include_directories(${PROJECT_HEADERS_DIR})
add_subdirectory(src)

include(CppLint)
ADD_STYLE_CHECK_TARGET(lint ${PROJECT_HEADERS_DIR} ${PROJECT_SOURCES_DIR})
