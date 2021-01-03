//
// Created by Pop Richards on 27/12/20.
//

#include "ZmqServer.hpp"

ZMQServer::ZMQServer(AbstractStatInterface * cpuStats, AbstractStatInterface * memStats) {
    std::cout << "ZMQ Server Created" << std::endl;
    // Store stat objects
    ZMQServer::cpuStats = cpuStats;
    ZMQServer::memStats = memStats;

    // Get Hostname of the system
    char host[HOST_NAME_MAX];
    gethostname(host, HOST_NAME_MAX);
    hostname["host"] = host;

}

void ZMQServer::Serve(std::string bindAddress) {
    using namespace std::chrono_literals;

    // Create socket structure
    zmq::context_t context{1};

    zmq::socket_t socket{context, zmq::socket_type::rep};
    // Bind with tcp address
    socket.bind(bindAddress);

    for(;;) {
        zmq::message_t request;

        // Wait for ZMQ request
        socket.recv(request, zmq::recv_flags::none);
        std::cout << "Received " << request.to_string() << std::endl;

        // Get stats and create a single json
        hostname.merge_patch(nlohmann::json::parse(cpuStats->getCPUUsage()));
        hostname.merge_patch(nlohmann::json::parse(memStats->getMemoryUsage()));

        // Send Json response as a ZMQ reply
        socket.send(zmq::buffer(hostname.dump()), zmq::send_flags::none);
    }
}