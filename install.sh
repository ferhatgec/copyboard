#!/bin/sh

g++ -std=c++17 -I./include/ -I./Library/ ./src/Parser.cpp ./src/CopyBoard.cpp -o /bin/copyboard
