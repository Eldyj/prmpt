#!/bin/sh
tcc -o prmpt index.c && \
[ "$1" = "install" ] && \
mkdir -p ~/.local/bin && \
cp prmpt ~/.local/bin
