#!/bin/bash
gcc -O3 code/packing_4.c -L/home/fpelogia/algencan/lib -lalgencan -lgfortran -lm   -o algencan
./algencan 10 10 1.5 1 2.8 3 5 5.5 7 4.4
