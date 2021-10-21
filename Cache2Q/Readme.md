# Readme

## Build
To build the project firstly you need clone the repository to your local computer.
```
git clone https://github.com/pavel-collab/Intel-Ilab/tree/main/Cache2Q
```
Open the cloned directory and build the project.
```
mkdir build && cd build
cmake ..
make
```
After that an executable file named out will be in current directory (build). 

You can give the file with data to enter of executable file
```
./out < data_file_name
```

To view more information about programm work uncomment the first line in the file src/main.cpp.
```
// #define DEBUG
```

## Valgrind

```
valgrind --log-file="../valgrind.log" ./out < data_file_name
```