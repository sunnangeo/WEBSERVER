cmake_minimum_required(VERSION 3.10)
project (webserver)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

add_definitions("-Wall -g")
set(CMAKE_CXX_TYPE Debug)
set(EXECUTABLE_OUTPUT_PATH ../bin)
aux_source_directory (src SRC_CUR)

include_directories(include)
#link_directories (/usr/lib64/mysql/) # 库文件搜索路径


add_executable (server ${SRC_CUR})

TARGET_LINK_LIBRARIES(server mysqlclient)
TARGET_LINK_LIBRARIES(server pthread)


