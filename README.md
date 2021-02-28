# Installing Ubuntu18.04, CUDA toolkit 10.1, cuDNN, Torchlib C++, cmake, VS code and OpenCV for machine learning.
![](test_debug.png)



### Step x. Make Install OpenCV
    $ mkdir build
    $ cd build
    $ sudo cmake -D OPENCV_GENERATE_PKGCONFIG=ON WITH_GTK=ON ..
    $ sudo make install
    
### Step x. Install libgtk2.0-dev and pkg-config
    $ sudo apt-get install libgtk2.0-dev
    $ sudo apt-get install pkg-config
    
### Step x. Set ~/.Profile file with new path
    

    # set PATH for cuda 10.1 installation
    if [ -d "/usr/local/cuda-10.1/bin/" ]; then
        export PATH=/usr/local/cuda-10.1/bin${PATH:+:${PATH}}
        export LD_LIBRARY_PATH=/usr/local/cuda-10.1/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
        export LD_LIBRARY_PATH=/usr/local/cuda-10.2/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
    fi


