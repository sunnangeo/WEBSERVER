cmake_minimum_required(VERSION 3.10)
project (webserver)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

add_definitions("-Wall -g")
set(CMAKE_CXX_TYPE Debug)
set(EXECUTABLE_OUTPUT_PATH ../bin)
aux_source_directory (src SRC_CUR)
aux_source_directory (src/buffer SRC_BUFF)
aux_source_directory (src/http SRC_HTTP)
aux_source_directory (src/log SRC_LOG)
aux_source_directory (src/pool SRC_POOL)
aux_source_directory (src/server SRC_SERVER)
aux_source_directory (src/timer SRC_TIMER)

include_directories(include)
#link_directories (/usr/lib64/mysql/) # 库文件搜索路径


add_executable (server ${SRC_CUR} ${SRC_BUFF} ${SRC_HTTP} ${SRC_LOG} ${SRC_POOL} ${SRC_SERVER} ${SRC_TIMER})

TARGET_LINK_LIBRARIES(server mysqlclient)
TARGET_LINK_LIBRARIES(server pthread)


