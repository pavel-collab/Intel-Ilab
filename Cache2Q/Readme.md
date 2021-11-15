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
After that an executable files named main and perfect will be in current directory (build). 

To execute this file use

```
./main
```
or
```
./perfect
```

You can give the file with data to enter of executable file
```
./out < data_file_name
```

To view more information about programm work uncomment the first line in the file src/main.cpp.
```
// #define DEBUG
```

## Testing

In the project you can finde a firectory with data, named 001.dat, 002.dat ect. This files contained aet of data to test the programm. You can use sell script:

```
for i in ../tests/*.dat; do echo $i; ./main < $i; done
```

After that in your consol you will see all names of datafiles and result of program using such file.

## Valgrind

```
valgrind --log-file="../valgrind.log" ./out < data_file_name
```