#!/bin/bash

export CCC_CXX=clang++
export CXX=c++-clang
export CCC_CC=clang
export CC=ccc-clang

nodemon -e c,h --exec 'clear; scan-build make -e; exit 0'
