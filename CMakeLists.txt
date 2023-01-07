cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(workflow-demo)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
  src/main.cpp
)
