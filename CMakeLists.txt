cmake_minimum_required(VERSION 3.20)

# project name
project(Texterfasser VERSION 0.1)

set(Qt6_ROOT "C:/Qt/6.12.0/msvc2022_64")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# let cmake locate the required Qt6 packages
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

# add the executable
add_executable(Texterfasser)

#specify the source code of the project
target_sources(Texterfasser PRIVATE Main.cpp)

target_link_libraries(Texterfasser PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)


