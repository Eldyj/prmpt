#!/bin/sh
tcc -o prmpt index.c && \
mkdir -p ~/.local/bin && \
cp prmpt ~/.local/bin
