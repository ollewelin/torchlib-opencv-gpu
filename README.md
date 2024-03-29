# Installing Ubuntu18.04, CUDA toolkit 10.1, cuDNN, Torchlib C++, cmake, VS code and OpenCV for machine learning.
![](test_debug.png)

### Youtube video serie 1,2,3

Part 1 video:
https://youtu.be/Ov5vyJR55iQ

Part 2 video:
https://youtu.be/D7WRwYmIUfE

Part 3 video:
https://youtu.be/HvolUKvMrxI

### Install CUDA toolkit and cuDNN

https://medium.com/@stephengregory_69986/installing-cuda-10-1-on-ubuntu-20-04-e562a5e724a0#fa83

#### Condensed commands for install CUDA 10.1 + cuDNN 

#### Clean
	sudo rm /etc/apt/sources.list.d/cuda*
	sudo apt remove --autoremove nvidia-cuda-toolkit
	sudo apt remove --autoremove nvidia-*

	sudo apt-get purge nvidia*
	sudo apt-get autoremove
	sudo apt-get autoclean

#### Installation

	sudo apt update
	sudo add-apt-repository ppa:graphics-drivers

	sudo apt-key adv --fetch-keys http://developer.download.nvidia.com/compute/cuda/repos/ubuntu1804/x86_64/7fa2af80.pub

	sudo bash -c 'echo "deb http://developer.download.nvidia.com/compute/cuda/repos/ubuntu1804/x86_64 /" > /etc/apt/sources.list.d/cuda.list'

	sudo bash -c 'echo "deb http://developer.download.nvidia.com/compute/machine-learning/repos/ubuntu1804/x86_64 /" > /etc/apt/sources.list.d/cuda_learn.list'

	sudo apt update
	sudo apt install cuda-10-1
	sudo apt install libcudnn7
	
#### Or last command testing 2021-10-19, versions CUDA 10.2 and cuDNN 8

	sudo apt install cuda-10-2
	sudo apt install libcudnn8


#### Modify the ~/.Profile file with extended path 10.1 and 10.2 
Start a terminal
    Ctrl-Alt-T
    
    $ sudo apt-get update
    $ sudo apt-get install vim
    $ sudo vim ~/.profile
    
Edit file and change
A convinent guide how to use vim editor:
https://coderwall.com/p/adv71w/basic-vim-commands-for-getting-started
    
    # set PATH for cuda 10.1 installation
    if [ -d "/usr/local/cuda-10.1/bin/" ]; then
        export PATH=/usr/local/cuda-10.1/bin${PATH:+:${PATH}}
        export LD_LIBRARY_PATH=/usr/local/cuda-10.1/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
        export LD_LIBRARY_PATH=/usr/local/cuda-10.2/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
    fi

#### Or last command testing 2021-10-19, versions CUDA 10.2 and cuDNN 8
	
	# set PATH for cuda 10.2 installation
		if [ -d "/usr/local/cuda-10.2/bin/" ]; then
    		export PATH=/usr/local/cuda-10.2/bin${PATH:+:${PATH}}
    		export LD_LIBRARY_PATH=/usr/local/cuda-10.2/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
	fi

#### reboot
    $ sudo reboot
    
### Check CUDA and cuDNN installation

#### Check Nvidia dirver
    $ nvidia-smi

Example answer:

    Tue Mar  2 19:19:42 2021       
    +-----------------------------------------------------------------------------+
    | NVIDIA-SMI 460.39       Driver Version: 460.39       CUDA Version: 11.2     |
    |-------------------------------+----------------------+----------------------+
    | GPU  Name        Persistence-M| Bus-Id        Disp.A | Volatile Uncorr. ECC |
    | Fan  Temp  Perf  Pwr:Usage/Cap|         Memory-Usage | GPU-Util  Compute M. |
    |                               |                      |               MIG M. |
    |===============================+======================+======================|
    |   0  GeForce GTX 1650    Off  | 00000000:01:00.0 Off |                  N/A |
    | N/A   42C    P8     3W /  N/A |      5MiB /  3911MiB |      0%      Default |
    |                               |                      |                  N/A |
    +-------------------------------+----------------------+----------------------+
                                                                                   
    +-----------------------------------------------------------------------------+
    | Processes:                                                                  |
    |  GPU   GI   CI        PID   Type   Process name                  GPU Memory |
    |        ID   ID                                                   Usage      |
    |=============================================================================|
    |    0   N/A  N/A      1510      G   /usr/lib/xorg/Xorg                  4MiB |
    +-----------------------------------------------------------------------------+

#### Check CUDA
    $ nvcc --version

Example answer:

    nvcc: NVIDIA (R) Cuda compiler driver
    Copyright (c) 2005-2019 NVIDIA Corporation
    Built on Sun_Jul_28_19:07:16_PDT_2019
    Cuda compilation tools, release 10.1, V10.1.243

#### Or last command testing 2021-10-19, versions CUDA 10.2 and cuDNN 8

	nvcc: NVIDIA (R) Cuda compiler driver
	Copyright (c) 2005-2019 NVIDIA Corporation
	Built on Wed_Oct_23_19:24:38_PDT_2019
	Cuda compilation tools, release 10.2, V10.2.89


#### 2.3.2. Debian Installation
https://docs.nvidia.com/deeplearning/cudnn/install-guide/index.html

#### Download cuDNN from NVIDIA Archive 
To get rid of cmake error issue:
..
Could NOT find CUDNN (missing: CUDNN_LIBRARY_PATH CUDNN_INCLUDE_PATH)
..

https://developer.nvidia.com/rdp/cudnn-archive
Make an account
and download

I was select from

Download cuDNN v8.0.4 (September 28th, 2020), for CUDA 10.1

	cuDNN Runtime Library for Ubuntu18.04 (Deb)
	cuDNN Developer Library for Ubuntu18.04 (Deb)
	cuDNN Code Samples and User Guide for Ubuntu18.04 (Deb)

Then Install the runtime library, for example:

	~/Downloads$ sudo dpkg -i libcudnn8_8.0.4.30-1+cuda10.1_amd64.deb
	~/Downloads$ sudo dpkg -i libcudnn8-dev_8.0.4.30-1+cuda10.1_amd64.deb
	~/Downloads$ sudo dpkg -i libcudnn8-samples_8.0.4.30-1+cuda10.1_amd64.deb

#### Or last command testing 2021-10-19, versions CUDA 10.2 and cuDNN 8
Download cuDNN v8.2.4 , for CUDA 10.2

	$ sudo dpkg -i libcudnn8_8.2.4.15-1+cuda10.2_amd64.deb
	$ sudo dpkg -i libcudnn8-dev_8.2.4.15-1+cuda10.2_amd64.deb
	$ sudo dpkg -i libcudnn8-samples_8.2.4.15-1+cuda10.2_amd64.deb


#### Check cuDNN

    $ /sbin/ldconfig -N -v $(sed ‘s/:/ /’ <<< $LD_LIBRARY_PATH) 2>/dev/null | grep libcudnn

Example answer:

    sed: -e expression #1, char 1: unknown command: `�'
	libcudnn_adv_train.so.8 -> libcudnn_adv_train.so.8.0.4
	libcudnn_ops_train.so.8 -> libcudnn_ops_train.so.8.0.4
	libcudnn_cnn_train.so.8 -> libcudnn_cnn_train.so.8.0.4
	libcudnn_ops_infer.so.8 -> libcudnn_ops_infer.so.8.0.4
	libcudnn_adv_infer.so.8 -> libcudnn_adv_infer.so.8.0.4
	libcudnn_cnn_infer.so.8 -> libcudnn_cnn_infer.so.8.0.4
	libcudnn.so.7 -> libcudnn.so.7.6.5
	libcudnn.so.8 -> libcudnn.so.8.0.4
    
Or

	sed: -e expression #1, char 1: unknown command: `�'
	libcudnn_ops_train.so.8 -> libcudnn_ops_train.so.8.2.4
	libcudnn_cnn_infer.so.8 -> libcudnn_cnn_infer.so.8.2.4
	libcudnn.so.7 -> libcudnn.so.7.6.5
	libcudnn_ops_infer.so.8 -> libcudnn_ops_infer.so.8.2.4
	libcudnn_adv_train.so.8 -> libcudnn_adv_train.so.8.2.4
	libcudnn_cnn_train.so.8 -> libcudnn_cnn_train.so.8.2.4
	libcudnn.so.8 -> libcudnn.so.8.2.4
	libcudnn_adv_infer.so.8 -> libcudnn_adv_infer.so.8.2.4

    
### Download libtorch
https://pytorch.org/

    PyTorch Build: Stable (1.7.1)
    Your OS: Linux
    Package: libtorch
    CUDA: 10.1
    
Download here (cxx11 ABI):      
https://download.pytorch.org/libtorch/cu101/libtorch-cxx11-abi-shared-with-deps-1.7.1%2Bcu101.zip

#### Make a test directory hello1
    $ mkdir hello1
    $ cd hello1
    /hello1$ wget https://download.pytorch.org/libtorch/cu101/libtorch-cxx11-abi-shared-with-deps-1.7.1%2Bcu101.zip
    
#### Unzip libtorch zipfile in hello1 directory
    /hello1$ unzip libtorch-cxx11-abi-shared-with-deps-1.7.1+cu101.zip

### Install cmake
    $ sudo apt-get update
    $ sudo apt-get install cmake
    
### Install git
	$ sudo apt-get update
	$ sudo apt-get install git

### Install OpenCV

	$ git clone https://github.com/opencv/opencv
	$ cd opencv

#### Install libgtk2.0-dev and pkg-config if issues with libgtk2.0-dev and pkg-config
    
    $ sudo apt-get install libgtk2.0-dev
    $ sudo apt-get install pkg-config


#### Make a build directory
    
    /opencv$ mkdir build
    /opencv$ cd build

#### Do cmake with OPENCV_GENERATE_PKGCONFIG=ON and with WITH_GTK=ON
Both OPENCV_GENERATE_PKGCONFIG=ON and WITH_GTK=ON need to be turned ON to not get error later.

    /opencv/build$ sudo cmake -D OPENCV_GENERATE_PKGCONFIG=ON WITH_GTK=ON ..
    /opencv/build$ sudo make

#### Time... for coffe :)
#### Put files into the system folder with this command:

    /opencv/build$ sudo make install
    
### Use Visual Studio Code IDE editor.

#### Install Visual Studio Code 
https://code.visualstudio.com/docs/setup/linux

    $ sudo snap install --classic code
    
#### Download test code, C++ main.cpp and CMakeFiles.txt (this repository).

	$ cd hello1
	/hello1$ git clone https://github.com/ollewelin/torchlib-opencv-gpu
	/hello1$ cd torchlib-opencv-gpu	
	/hello1/torchlib-opencv-gpu$ mv *.* ../
	/hello1/torchlib-opencv-gpu$ cd ..
	/hello1$ sudo rm -r torchlib-opencv-gpu
	
	
#### Start Visual Studio Code IDE with test files.

	/hello1$ code .

#### Include OpenCV path to VS code

	In VS code IDE:
	Wiev -> Command pallete.. -> C++: Edit Configurations (UI)
	add to Include path
	
	/usr/local/include/opencv4
##### Save settings
	CTRL-S

![](include_opencv4_vc.png)

#### Important change CMakeLists.txt path with your working directory path
	/hello1$ cd ..
	/$ pwd
reply example 

	/home/tiny/olle1
	
Edit your path into CMakeLists.txt file
Example:

	...
	set(OpenCV_DIR /home/tiny/olle1/OpenCV/opencv-master/build)
	...
	list(APPEND CMAKE_PREFIX_PATH "/home/tiny/olle1/hello1/libtorch")
	...
	

#### Use cmake debug option
	
	/hello1$ cmake -DCMAKE_BUILD_TYPE=Debug .
	
#### Use cmake without debug option	
	/hello1$ cmake CMakeLists.txt
	
#### Example how it looks on my other partition

	tiny@tiny-TUF-Gaming-FX505DT-FX505DT:~/olle1/hello5$ cmake CMakeLists.txt
	-- The C compiler identification is GNU 7.5.0
	-- The CXX compiler identification is GNU 7.5.0
	-- Check for working C compiler: /usr/bin/cc
	-- Check for working C compiler: /usr/bin/cc -- works
	-- Detecting C compiler ABI info
	-- Detecting C compiler ABI info - done
	-- Detecting C compile features
	-- Detecting C compile features - done
	-- Check for working CXX compiler: /usr/bin/c++
	-- Check for working CXX compiler: /usr/bin/c++ -- works
	-- Detecting CXX compiler ABI info
	-- Detecting CXX compiler ABI info - done
	-- Detecting CXX compile features
	-- Detecting CXX compile features - done
	-- Looking for pthread.h
	-- Looking for pthread.h - found
	-- Looking for pthread_create
	-- Looking for pthread_create - not found
	-- Looking for pthread_create in pthreads
	-- Looking for pthread_create in pthreads - not found
	-- Looking for pthread_create in pthread
	-- Looking for pthread_create in pthread - found
	-- Found Threads: TRUE  
	-- Found CUDA: /usr/local/cuda-10.1 (found version "10.1") 
	-- Caffe2: CUDA detected: 10.1
	-- Caffe2: CUDA nvcc is: /usr/local/cuda-10.1/bin/nvcc
	-- Caffe2: CUDA toolkit directory: /usr/local/cuda-10.1
	-- Caffe2: Header version is: 10.1
	-- Found CUDNN: /usr/lib/x86_64-linux-gnu/libcudnn.so  
	-- Found cuDNN: v8.0.4  (include: /usr/include, library: /usr/lib/x86_64-linux-gnu/libcudnn.so)
	-- Autodetected CUDA architecture(s):  7.5
	-- Added CUDA NVCC flags for: -gencode;arch=compute_75,code=sm_75
	-- Found Torch: /home/tiny/olle1/hello5/libtorch-cxx11-abi-shared-with-deps-1.7.1+cu101/libtorch/lib/libtorch.so  
	-- Found OpenCV: /home/tiny/olle1/OpenCV/opencv-master/build (found version "4.5.1") 
	-- Configuring done
	-- Generating done
	-- Build files have been written to: /home/tiny/olle1/hello5
	tiny@tiny-TUF-Gaming-FX505DT-FX505DT:~/olle1/hello5$ 

	
#### Compile and run test program

	/hello1$ make
	/hello1$ ./main
	

#### Run debug inside VS code
Mark main.cpp in file explorer
explorer -> main.cpp

Run -> Start Debugging 
or
F5

Select
C++(GDB/LLDB)


Edit launch.json file and change

	..
	"program": "enter program name, for example ${workspaceFolder}/a.out",
	..
to 

	..
	"program": "main",
	..
save
Ctrl-S

	Run -> Start debugging 
	of
	F5
	
If the launch.json only contain this:
```
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        
    ]
}
```
Then click Add configuration 


![](add_conf_launch_json.jpeg)

```
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "enter program name, for example ${workspaceFolder}/a.out",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description":  "Set Disassembly Flavor to Intel",
                    "text": "-gdb-set disassembly-flavor intel",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```

![](add_conf_launch_json_step2.jpeg)

Change launch.json file "program"

```
....
            "program": "main",
....
```
![](add_conf_launch_json_step3.jpeg)

Then debug view look like this:

![](debug.png)

#### CUDA 10.2 cmake and make with main.cpp from GPU_gradient_test 2021-10-27

```
olle@olle-TUF-Gaming-FX505DT-FX505DT:~/pytorch_cpp$ cmake CMakeLists.txt
-- The C compiler identification is GNU 7.5.0
-- The CXX compiler identification is GNU 7.5.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Failed
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - found
-- Found Threads: TRUE  
-- Found CUDA: /usr/local/cuda-10.2 (found version "10.2") 
-- Caffe2: CUDA detected: 10.2
-- Caffe2: CUDA nvcc is: /usr/local/cuda-10.2/bin/nvcc
-- Caffe2: CUDA toolkit directory: /usr/local/cuda-10.2
-- Caffe2: Header version is: 10.2
-- Found CUDNN: /usr/lib/x86_64-linux-gnu/libcudnn.so  
-- Found cuDNN: v8.2.4  (include: /usr/include, library: /usr/lib/x86_64-linux-gnu/libcudnn.so)
-- /usr/local/cuda-10.2/lib64/libnvrtc.so shorthash is 08c4863f
-- Autodetected CUDA architecture(s):  7.5
-- Added CUDA NVCC flags for: -gencode;arch=compute_75,code=sm_75
-- Found Torch: /home/olle/pytorch_cpp/libtorch/lib/libtorch.so  
-- Found OpenCV: /usr/local (found version "4.5.2") 
-- Configuring done
-- Generating done
-- Build files have been written to: /home/olle/pytorch_cpp
olle@olle-TUF-Gaming-FX505DT-FX505DT:~/pytorch_cpp$ 


olle@olle-TUF-Gaming-FX505DT-FX505DT:~/pytorch_cpp$ make
[ 50%] Building CXX object CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable main
[100%] Built target main
olle@olle-TUF-Gaming-FX505DT-FX505DT:~/pytorch_cpp$ ./main
 0  0  0  0  0
 0  0  0  0  0
[ CPUFloatType{2,5} ]
 0
 0
 0
 0
 0
[ CPUFloatType{5} ]
  0  16   0   0   0
  0   0   0   0   0
[ CPUFloatType{2,5} ]
CUDA is available! 
 0.8615  0.8352  0.5833
 0.9185  0.5853  0.7216
 0.8694  0.3485  0.6050
 0.9271  0.6108  0.3470
 0.0329  0.1904  0.3169
[ CUDAFloatType{5,3} ]
 0.8615  0.8352  0.5833  0.9185  0.5853
 0.7216  0.8694  0.3485  0.6050  0.9271
 0.6108  0.3470  0.0329  0.1904  0.3169
[ CUDAFloatType{3,5} ]
 17.3000   0.8352   0.5833   0.9185   0.5853
  0.7216   0.8694   0.3485   0.6050   0.9271
  0.6108   0.3470   0.0329   0.1904   0.3169
[ CUDAFloatType{3,5} ]
 0  0  0
 0  0  0
[ CPUFloatType{2,3} ]
  0  16   0   0   0
  0   0   0   0   0
[ CUDAFloatType{2,5} ]
More basic tests
 3
 2
[ CUDALongType{2} ]
************* GPU t5 tensor **************
 11  12  13
 14  15  16
[ CUDAFloatType{2,3} ]
************* Reshape t5 tensor code  t5.reshape({3,2}) no change **************
 11  12  13
 14  15  16
[ CUDAFloatType{2,3} ]
************* Reshape t5 = t5.reshape({3,2})  t5 tensor **************
 11  12
 13  14
 15  16
[ CUDAFloatType{3,2} ]

Make CPU tensor forward calculation 
c1_cpu = a1_cpu * b1_cpu = 15.9779
[ CPUFloatType{} ]
Make CPU tensor gradient calculation 
a1_cpu gradient = 2.8532
[ CPUFloatType{} ]
NOTE! b1_cpu gradient is disabled 
b1_cpu gradient = [ Tensor (undefined) ]
PyTorch Basics

Make GPU tensor forward calculation 
c1_gpu = a1_gpu * b1_gpu = 15.98
[ CUDAFloatType{} ]
Make GPU tensor gradient calculation 
a1_gpu gradient = 2.853
[ CUDAFloatType{} ]
b1_gpu gradient = 5.6
[ CUDAFloatType{} ]
olle@olle-TUF-Gaming-FX505DT-FX505DT:~/pytorch_cpp$ 
```
