#!/bin/bash
# filepath: /Users/srijansahay/Library/CloudStorage/OneDrive-Personal/BITS-CourseWork/2-1/CP/Programs/LAB9/Lab Sheet 9/structCProj/structCProj/compile.sh

# Compile the program
gcc -o main_library main_library.c books_catalog.c book_fun.c -I. -Wall -Wextra

# Check if compilation was successful
if [ $? -eq 0 ]; then
  echo "Compilation successful. Run the program using ./main_library"
else
  echo "Compilation failed. Please check for errors."
fi
