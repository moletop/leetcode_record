cmake_minimum_required(VERSION 3.19)
project(leetcode_c__)

set(CMAKE_CXX_STANDARD 14)

# 以下3种方式遍历cpp文件，请任选一种(推荐1)。
# 1.递归方式遍历文件。（缺点是在右上角Configurations中多出一个CMakeCXXCompilerId，无伤大雅）
file(GLOB_RECURSE files *.cpp)

# 2.手动指定遍历那些目录下的cpp文件
#file(GLOB files *.cpp dir_name/*.cpp)

# 3.只遍历项目根目录下的cpp
#file(GLOB files *.cpp)

foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable(${exe} ${file})
    message(\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
