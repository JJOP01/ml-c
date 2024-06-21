#!/bin/sh

set -xe

clang -Wall -Wextra -o double double.c -lm
clang -Wall -Wextra -o gates gates.c -lm
clang -Wall -Wextra -o xor xor.c -lm

usgae()
{
   echo "Usage: $0 -a parameterA -b parameterB -c parameterC"
   echo -e "\t-r run the generated output executables"
   exit 1
}

for a in "$@"; do
    if [ "$a" = "-r" ]; then
        ./gates && ./xor > nul
    fi
done
