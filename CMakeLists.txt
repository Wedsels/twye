cmake_minimum_required(VERSION 3.10)
project(MyProject)

add_compile_definitions(UNICODE _UNICODE)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /DEBUG:NONE")
add_definitions(-D_ITERATOR_DEBUG_LEVEL=0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "C:/Users/fear8/Downloads/ModEngine-2.1.0.0-win64/External")

add_library("twye" SHARED "twye.cpp")
target_include_directories("twye" PRIVATE ${CMAKE_SOURCE_DIR}/LibER/include)
target_link_libraries("twye" PUBLIC "${CMAKE_SOURCE_DIR}/LibER/build/Release/libER_static.lib")

target_compile_options("twye" PRIVATE /O2 /Os /GL /GS- /Gy /Zc:inline /Gw)
target_link_options("twye" PRIVATE /LTCG /OPT:REF /OPT:ICF)
set_target_properties("twye" PROPERTIES INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)