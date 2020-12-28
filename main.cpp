#include <iostream>
#include "server/ServerFactoryImpl.hpp"
#include "stats/AbstractStatInterface.hpp"
#include "stats/CPUStatImpl.hpp"
#include "stats/MemStatImpl.hpp"

int main() {
    std::cout << "Starting Monitor-sender" << std::endl;

    AbstractStatInterface * cpuStat = new CPUStatImpl("procstat");
    AbstractStatInterface * memStat = new MEMStatImpl("sysconf");

    ServerFactoryImpl * serverFactory = ServerFactoryImpl::GetServerFactoryInstance();
    ServerFactory * server = serverFactory->CreateServer("zmq", cpuStat, memStat);
    server->Serve("tcp://*:5555", 1);
    std::cout << "Monitor-sender exited" << std::endl;
    return 0;
}
