cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(main)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_LIBRARY_PATH "/usr/local/cuda-10.2/targets/x86_64-linux/lib")
set(OpenCV_DIR /home/tiny/olle1/OpenCV/opencv-master/build)

#If you want to use debugging mode then use this cmake set command line below
#set(CMAKE_BUILD_TYPE=Debug)
#or use this cmake directive -DCMAKE_BUILD_TYPE=Debug .
#cmake -DCMAKE_BUILD_TYPE=Debug .

#list(APPEND CMAKE_PREFIX_PATH "//home/tiny/olle1/hello1/libtorch-cxx11-abi-shared-with-deps-1.7.1+cu101/libtorch")
list(APPEND CMAKE_PREFIX_PATH "/home/tiny/olle1/hello1/libtorch")
find_package(Torch REQUIRED)  
find_package(OpenCV REQUIRED)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lm -ldl")
add_executable(main main.cpp)
target_link_libraries(main ${TORCH_LIBRARIES} ${OpenCV_LIBS})
set_property(TARGET main PROPERTY CXX_STANDARD 14)
