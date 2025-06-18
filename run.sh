#!/bin/bash

mkdir -p bin

FILES=$(find src -name "*.cpp")

g++ $FILES -o bin/sfml-app \
  -std=c++17 \
  -Iinclude \
  -Idependencies/SFML/include \
  -Idependencies/miniaudio \
  -Ldependencies/SFML/lib \
  -lsfml-graphics -lsfml-window -lsfml-system -lpthread

DYLD_LIBRARY_PATH=dependencies/SFML/lib ./bin/sfml-app
