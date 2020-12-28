//
// Created by Pop Richards on 27/12/20.
//

#include "ZmqServer.hpp"

ZMQServer::ZMQServer(AbstractStatInterface * cpuStats, AbstractStatInterface * memStats) {
    std::cout << "ZMQ Server Created" << std::endl;
    ZMQServer::cpuStats = cpuStats;
    ZMQServer::memStats = memStats;
}

void ZMQServer::Serve(std::string bindAddress, int statCollationTimer) {
    using namespace std::chrono_literals;

    std::chrono::seconds dur(statCollationTimer);
    zmq::context_t context{1};

    zmq::socket_t socket{context, zmq::socket_type::rep};
    socket.bind(bindAddress);

    for(;;) {
        zmq::message_t request;

        socket.recv(request, zmq::recv_flags::none);
        std::cout << "Received " << request.to_string() << std::endl;
        std::this_thread::sleep_for(dur);

        nlohmann::json cpuJson = nlohmann::json::parse(cpuStats->getCPUUsage());
        nlohmann::json memJson = nlohmann::json::parse(memStats->getMemoryUsage());

        cpuJson.merge_patch(memJson);
        socket.send(zmq::buffer(cpuJson.dump()), zmq::send_flags::none);
    }
}