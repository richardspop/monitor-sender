//
// Created by Pop Richards on 27/12/20.
//

#include "ServerFactoryImpl.hpp"

ServerFactoryImpl::ServerFactoryImpl() {
    std::cout << "Server Factory Impl Created" << std::endl;
}

ServerFactoryImpl * ServerFactoryImpl::GetServerFactoryInstance() {
    if (!instance)
        instance = new ServerFactoryImpl();
    std::cout << "ServerFactoryImpl instance returned" << std::endl;
    return instance;
}

ServerFactory * ServerFactoryImpl::CreateServer(std::string serverType, AbstractStatInterface * cpuStats, AbstractStatInterface * memStats) {
    if (serverType == "zmq") {
        return new ZMQServer(cpuStats, memStats);
    } else {
        std::cout << "Error: undefined server type " << serverType << std::endl;
    }
    return nullptr;
}