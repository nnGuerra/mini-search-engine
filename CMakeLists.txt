cmake_minimum_required(VERSION 3.10)

project(MiniSearchEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(search_engine
    src/main.cpp
    src/loader/DocumentLoader.cpp
    src/tokenizer/Tokenizer.cpp
    src/filter/Filter.cpp
)