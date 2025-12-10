#!/bin/bash

set -e
g++ -std=c++17 -I./sorting/include -I./tests/lib ./sorting/src/*.cpp ./tests/*.cpp -o sem_1


echo "COMPILATION COMPLETE"
echo "RUNNING TESTS..."
./sem_1