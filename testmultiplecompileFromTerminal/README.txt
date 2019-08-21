#Create two files a function is called from another file. N.B. main function will be reside on ly in one file 

#https://www.cs.fsu.edu/~myers/howto/g++compiling.txt

# one way we can run, it is cmipling (object code) and link with the executable  simultaneously
g++ -o myProgram cpptest.cpp main.cpp

# other way, first create object file, then link
g++ -o myProgram1.o -c cpptest.cpp 
g++ -o myProgram2.o -c main.cpp 
g++ -o myProgram.exe myProgram1.o myProgram2.o

or
g++ -o myProgram myProgram1.o myProgram2.o

// otherway

g++ -c cpptest.cpp 
g++ -c main.cpp 
g++ -o myProgram cpptest.o main.o

or
g++ -o myProgram.exe cpptest.o main.o

#You can create bash file and run the bash file as the following way:
#save the file named as run.sh

#!/bin/bash

chmod +x run.sh
g++ -c cpptest.cpp 
g++ -c main.cpp 
g++ -o myProgram cpptest.o main.o
