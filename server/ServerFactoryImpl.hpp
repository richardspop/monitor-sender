//
// Created by Pop Richards on 27/12/20.
//

#ifndef MONITOR_SENDER_SERVERFACTORYIMPL_HPP
#define MONITOR_SENDER_SERVERFACTORYIMPL_HPP

#include "ServerFactory.hpp"
#include <iostream>
#include "ZmqServer.hpp"
#include "../stats/AbstractStatInterface.hpp"

class ServerFactoryImpl {
private:
    ServerFactoryImpl();
    inline static ServerFactoryImpl * instance;
public:
    static ServerFactoryImpl * GetServerFactoryInstance();

    ServerFactory * CreateServer(std::string serverType, AbstractStatInterface * cpuStats, AbstractStatInterface * memStats);
};


#endif //MONITOR_SENDER_SERVERFACTORYIMPL_HPP
