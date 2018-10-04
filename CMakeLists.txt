# require minimum cmake version 2.8
cmake_minimum_required (VERSION 2.8)

enable_language(CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/general)

# adding a project
project (Kattis)

set(TARGETS money)
FOREACH(t ${TARGETS})
    add_executable(${t} ${PROJECT_SOURCE_DIR}/${t}/main.cpp ${PROJECT_SOURCE_DIR}/general/logger.cpp)
    set_target_properties( ${t} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${t}/ )
    target_include_directories( ${t} PUBLIC ${PROJECT_SOURCE_DIR}/general )
ENDFOREACH(t)


#################################################################################################################
#add_executable(14ms ${PROJECT_SOURCE_DIR}/2017/14ms/main.cpp ${PROJECT_SOURCE_DIR}/general/knot.cpp ${PROJECT_SOURCE_DIR}/general/logger.cpp)
#set_target_properties( 14ms PROPERTIES RUNTIME_OUTPUT_DIRECTORY 2017/14ms/ )
#target_include_directories( 14ms PUBLIC ${PROJECT_SOURCE_DIR}/general )
