rm *.o
rm exe

gcc -c linkedList.c
gcc -c main.c
gcc -o exe linkedList.o main.o
./exe