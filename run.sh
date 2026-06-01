#!/bin/bash

touch $1.in $1.out
g++ -std=c++23 -Wall -Wextra $1.cpp -o out.o
./out.o < $1.in > $1.out

# 配置path:
# #!/usr/bin/env bash
# exec "$HOME/code/aeyone-algorithm-note/run.sh" "$@"