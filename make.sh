#!/bin/sh
tcc -O3 -Wall -o prmpt index.c && \
mkdir -p ~/.local/bin && \
cp prmpt ~/.local/bin
