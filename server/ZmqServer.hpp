//
// Created by Pop Richards on 27/12/20.
//

#ifndef MONITOR_SENDER_ZMQSERVER_HPP
#define MONITOR_SENDER_ZMQSERVER_HPP
#include "ServerFactory.hpp"
#include "../stats/AbstractStatInterface.hpp"
#include "../nlohmann/json.hpp"

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <limits.h>

#include <zmq.hpp>

class ZMQServer: public ServerFactory{
private:
    nlohmann::json hostname;
    AbstractStatInterface * cpuStats;
    AbstractStatInterface * memStats;
public:
    ZMQServer(AbstractStatInterface * cpuStats, AbstractStatInterface * memStats);
    void Serve(std::string bindAddress);
};


#endif //MONITOR_SENDER_ZMQSERVER_HPP
