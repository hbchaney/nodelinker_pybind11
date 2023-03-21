cmake_minimum_required(VERSION 3.4...3.18)
project(NodeLinker)

add_subdirectory(pybind11)
pybind11_add_module(${PROJECT_NAME} src/main.cpp)

add_subdirectory(src/extras)
target_link_directories(${PROJECT_NAME} PRIVATE src/extras)
target_link_libraries(${PROJECT_NAME} PRIVATE utls)
target_include_directories(${PROJECT_NAME} PRIVATE src/extras)


