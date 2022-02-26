#!/bin/bash
#Run this in terminal
#+ Command to compile c++ program. here i used common one

cd src

g++ map.cpp functions.cpp -o map-rot

./map-rot

cd ../data

gnuplot -persist << load 'fig.gnu'
exit 0
