cmake_minimum_required(VERSION 3.10)
project(displayiq)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

include_directories(include)

add_executable(enhance main.cpp src/enhancement.cpp)
target_link_libraries(enhance ${OpenCV_LIBS})

pybind11_add_module(displayiq_cpp bindings/pybind_module.cpp src/enhancement.cpp)
target_link_libraries(displayiq_cpp PRIVATE ${OpenCV_LIBS})