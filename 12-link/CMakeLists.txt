cmake_minimum_required(VERSION 3.10)
project(Josephus)

# 设置C标准
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 包含头文件目录
include_directories(include)

# 添加源文件
set(SOURCE_FILES
    josephus.c
    ll/ll.c
)

# 添加可执行文件
add_executable(josephus ${SOURCE_FILES})

# 如果有其他库或依赖项，可以在这里添加链接选项
# target_link_libraries(josephus ...)