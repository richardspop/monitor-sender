FROM 10.157.1.216:5000/microservice-base:v1
MAINTAINER richardspop@gmail.com

ENV DEBIAN_FRONTEND=noninteractive

#RUN apt-get update
#RUN apt-get install -y g++ curl make net-tools wget git pkg-config
#RUN mkdir -p /root/cmake

#COPY cmake/* /root/cmake/
#RUN /root/cmake/cmake-* --skip-license --prefix=/root/cmake/

#ENV PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/root/cmake/bin

RUN mkdir -p /root/monitor_sender

#RUN mkdir -p /root/monitor_sender/libzmq

#RUN mkdir -p /root/monitor_sender/nlohmann

COPY monitor_sender /root/monitor_sender/monitor_sender

#COPY cppzmq /root/monitor_sender/cppzmq

#COPY libzmq /root/monitor_sender/libzmq

#COPY nlohmann /root/monitor_sender/nlohmann

WORKDIR /root/monitor_sender

COPY install-dependencies.sh /root/monitor_sender/install-dependencies.sh
RUN /root/monitor_sender/install-dependencies.sh

ENTRYPOINT /root/monitor_sender/monitor_sender
