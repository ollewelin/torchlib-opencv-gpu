cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(example)
#If debug want the command use command 
#$ cmake -DCMAKE_BUILD_TYPE=Debug .
#otherwise
#$ cmake CMakeLists.txt
set(CMAKE_LIBRARY_PATH "/usr/local/cuda-10.2/targets/x86_64-linux/lib")
list(APPEND CMAKE_PREFIX_PATH "/home/tiny/olle1/hello1/libtorch")
set(CMAKE_CXX_STANDARD 14)
find_package(Torch REQUIRED)
add_executable(main main.cpp)
target_link_libraries(main ${TORCH_LIBRARIES})
