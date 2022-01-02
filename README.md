# paincave-21


## How to build and run on Mac/Linux
    mkdir build
    cd build
    cmake ..
    make
    ./paincave21

## How to build and debug on Mac/Linux
    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Debug ..
    make
    lldb paincave # or hook it to VS Code
