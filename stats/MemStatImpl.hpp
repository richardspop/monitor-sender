//
// Created by Pop Richards on 28/12/20.
//

#ifndef MONITOR_SENDER_MEMSTATIMPL_HPP
#define MONITOR_SENDER_MEMSTATIMPL_HPP

#include "AbstractStatInterface.hpp"
#include "AbstractStatImplInterface.hpp"
#include "MemSysconf.hpp"

class MEMStatImpl: public AbstractStatInterface {
    AbstractStatImplInterface * statImpl;
public:
    MEMStatImpl(std::string statSource);
    std::string getCPUUsage();
    std::string getMemoryUsage();
};


#endif //MONITOR_SENDER_MEMSTATIMPL_HPP
