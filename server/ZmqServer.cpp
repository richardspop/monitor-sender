//
// Created by Pop Richards on 27/12/20.
//

#include "ZmqServer.hpp"

ZMQServer::ZMQServer(AbstractStatInterface * cpuStats, AbstractStatInterface * memStats) {
    std::cout << "ZMQ Server Created" << std::endl;
    ZMQServer::cpuStats = cpuStats;
    ZMQServer::memStats = memStats;
    char host[HOST_NAME_MAX];
    gethostname(host, HOST_NAME_MAX);
    hostname["host"] = host;

}

void ZMQServer::Serve(std::string bindAddress) {
    using namespace std::chrono_literals;

    zmq::context_t context{1};

    zmq::socket_t socket{context, zmq::socket_type::rep};
    socket.bind(bindAddress);

    for(;;) {
        zmq::message_t request;

        socket.recv(request, zmq::recv_flags::none);
        std::cout << "Received " << request.to_string() << std::endl;

        hostname.merge_patch(nlohmann::json::parse(cpuStats->getCPUUsage()));
        hostname.merge_patch(nlohmann::json::parse(memStats->getMemoryUsage()));
        socket.send(zmq::buffer(hostname.dump()), zmq::send_flags::none);
    }
}