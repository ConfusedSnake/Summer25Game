#!/bin/bash

mkdir -p bin

g++ src/main.cpp -o bin/sfml-app \
  -std=c++17 \
  -Idependencies/SFML/include \
  -Idependencies/miniaudio \
  -Ldependencies/SFML/lib \
  -lsfml-graphics -lsfml-window -lsfml-system -lpthread

DYLD_LIBRARY_PATH=dependencies/SFML/lib ./bin/sfml-app
