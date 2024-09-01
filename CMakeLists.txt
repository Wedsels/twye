cmake_minimum_required(VERSION 3.10)
project(MyProject)

add_compile_definitions(UNICODE _UNICODE)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /DEBUG:NONE")
add_definitions(-D_ITERATOR_DEBUG_LEVEL=0)


add_library(twye SHARED "src/twye.cpp")
target_include_directories(twye PRIVATE ${CMAKE_SOURCE_DIR}/LibER/include)
target_link_libraries(twye PUBLIC "${CMAKE_SOURCE_DIR}/LibER/build/Release/libER_static.lib")

target_compile_options(twye PRIVATE /O2 /Os /GL /Gy /Zc:inline /Gw)
target_link_options(twye PRIVATE /LTCG /OPT:REF /OPT:ICF)
set_target_properties(twye PROPERTIES INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)

add_custom_command(TARGET twye POST_BUILD 
    COMMAND "${CMAKE_COMMAND}" -E copy 
        "$<TARGET_FILE:twye>"
        "C:/Users/fear8/Downloads/ModEngine-2.1.0.0-win64/External/$<TARGET_FILE_NAME:twye>")


add_library(twye_updater SHARED "src/twye_updater.cpp")
target_include_directories(twye_updater PRIVATE ${CMAKE_SOURCE_DIR}/LibER/include)
target_link_libraries(twye_updater PUBLIC "${CMAKE_SOURCE_DIR}/LibER/build/Release/libER_static.lib")

target_compile_options(twye_updater PRIVATE /O2 /Os /GL /Gy /Zc:inline /Gw)
target_link_options(twye_updater PRIVATE /LTCG /OPT:REF /OPT:ICF)
set_target_properties(twye_updater PROPERTIES INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)

add_custom_command(TARGET twye_updater POST_BUILD 
    COMMAND "${CMAKE_COMMAND}" -E copy 
        "$<TARGET_FILE:twye_updater>"
        "C:/Users/fear8/Downloads/ModEngine-2.1.0.0-win64/External/$<TARGET_FILE_NAME:twye_updater>")