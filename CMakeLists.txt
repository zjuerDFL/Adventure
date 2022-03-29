# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Adventure)

# 指定生成目标
add_executable(Adventure main.cpp map.cpp room.cpp roomplus.cpp)