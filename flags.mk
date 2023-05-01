CC=g++
CPPFLAGS=-std=c++14 -I/usr/local/opt/libomp/include -L/usr/local/opt/libomp/lib -lomp
CFLAGS=-O3 -g -Wall -fmessage-length=0 -Xpreprocessor -fopenmp -maes -msse4 -mtune=native
