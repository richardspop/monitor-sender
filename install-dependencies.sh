#!/bin/sh

git clone https://github.com/zeromq/libzmq.git

mkdir -p libzmq/build
cd libzmq/build
cmake ..
make -j4 install

cd ../../

git clone https://github.com/zeromq/cppzmq
mkdir -p cppzmq/build
cd cppzmq/build
cmake ..
make -j4 install

cd ../../

mkdir -p nlohmann
cd nlohmann
wget https://github.com/nlohmann/json/releases/download/v3.9.1/json.hpp
cd ../