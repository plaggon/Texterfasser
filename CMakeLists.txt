cmake_minimum_required(VERSION 3.20)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# project name
project(Texterfasser VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)

#specify sources to be all files in src
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_PROJECT_NAME Texterfasser)

#specify the executable project
add_executable(Texterfasser "${MY_SOURCES}")


#define the RESOURCES_PATH macro to find resources easily when using CMAKE, (comment when sending to others)
target_compile_definitions(Texterfasser PRIVATE RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/*")

#same thing as above but for usage without CMAKE, (uncomment when needed)
#target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="./resources/*")

# let cmake locate the required Qt6 packages
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

include($ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

find_package(leptonica)
find_package(Tesseract)


target_include_directories(Texterfasser PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(Texterfasser PRIVATE "$ENV{VCPKG_ROOT}")


target_link_libraries(Texterfasser PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
target_link_libraries(Texterfasser PRIVATE leptonica)
target_link_libraries(Texterfasser PRIVATE Tesseract::libtesseract)


