#!/bin/bash
gcc -fPIC -C *.C
gcc -shared *.o -o liball.so
