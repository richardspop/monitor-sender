# monitor-sender

## server
This is a server factory.
It is used to create different servers to push the stats out of the service.
This has the potential to create server of different protocols like ZMQ, HTTP, GRPC, etc.,

### ServerFactory
This is a factory design pattern based server implementation.
This provides a common interface for all server implementations.

### ServerFactoryImpl
This is a singleton implementation to create the various servers based on the passed in configuration.
This is used to create different implementation of the server.

### ZMQServer
ZMQServer is a ZMQ based server that binds and listens to a tcp port.
When a request comes in, it gets the hostname, cpu and mem stats and sends out a json response and zmq reply.

### Class Diagram
![Class Diagram](monitor_sender_class.png?raw=true "Title")

### Sequence Diagram
![Sequence Diagram](monitor_sender_sequence.png?raw=true "Title")