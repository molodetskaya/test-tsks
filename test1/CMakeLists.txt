cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 11)

project(main)

add_executable(main
  main.cpp
  src/StoryBoard.cpp
  test/TestStoryBoard.cpp
)

include_directories(
  src
  test
)