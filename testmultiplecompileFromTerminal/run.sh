#!/bin/bash

chmod +x run.sh
g++ -c cpptest.cpp 
g++ -c main.cpp 
g++ -o myProgram cpptest.o main.o
