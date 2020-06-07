#!/bin/bash
gcc -O3 code/packing_4.c -L/home/fpelogia/algencan/lib -lalgencan -lgfortran -lm -o algencan
./algencan
