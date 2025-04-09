#!/bin/bash

# Compile all .c files in the current directory
for file in *.c; do
    gcc -o "${file%.c}" "$file"
done

echo "Compilation complete!" 