# monitor-sender
C++ micro service to monitor system usage and export the stats to the receiver.

## server
This is a server factory.
It is used to create different servers to push the stats out of the service.
This has the potential to create server of different protocols like ZMQ, HTTP, GRPC, etc.,

## stats
This is the stats library
this is used to create stat instance from different sources
It is used to obtain various usage stats such as cpu, memory, HDD, network, etc.,.
Adapter design pattern is used to manage all the various configuration of resources.

# Design
![Design](monitor-sender-Designs.png?raw=true "Title")

# Sequence Diagram
![Sequence Diagram](monitor_sender_sequence.png?raw=true "Title")