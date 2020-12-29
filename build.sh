#!/bin/sh

./install-dependencies.sh

cmake -G "CodeBlocks - Unix Makefiles" /root/monitor-sender/
make

export DEBIAN_FRONTEND=noninteractive

apt-get install -y apt-transport-https ca-certificates curl gnupg-agent software-properties-common lsb-release

curl -fsSL https://download.docker.com/linux/ubuntu/gpg | apt-key add -
add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
apt-get update
apt-get install -y docker-ce docker-ce-cli containerd.io

docker build -t monitor-sender:v1 .

