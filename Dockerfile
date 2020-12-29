FROM 10.157.1.216:5000/microservice-base:v1.0-5-gefc87df
MAINTAINER richardspop@gmail.com

ENV DEBIAN_FRONTEND=noninteractive

RUN mkdir -p /root/monitor_sender

COPY monitor_sender /root/monitor_sender/monitor_sender

WORKDIR /root/monitor_sender

COPY install-dependencies.sh /root/monitor_sender/install-dependencies.sh
RUN /root/monitor_sender/install-dependencies.sh

ENTRYPOINT /root/monitor_sender/monitor_sender
