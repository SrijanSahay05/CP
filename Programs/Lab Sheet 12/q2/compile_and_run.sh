#!/bin/bash

# Compile the program
gcc -c linkedList_Student.c
gcc -c main_StudentList.c
gcc -o student_list linkedList_Student.o main_StudentList.o

# Run the program
./student_list

# Clean up object files
rm -f *.o student_list 