//
// Created by Pop Richards on 27/12/20.
//

#ifndef MONITOR_SENDER_STATIMPL_HPP
#define MONITOR_SENDER_STATIMPL_HPP

#include "AbstractStatInterface.hpp"
#include "AbstractStatImplInterface.hpp"
#include "CpuProcStat.hpp"
#include <iostream>

class CPUStatImpl: public AbstractStatInterface {
    AbstractStatImplInterface * statImpl;
public:
    CPUStatImpl(std::string statSource);
    std::string getCPUUsage();
    std::string getMemoryUsage();

};


#endif //MONITOR_SENDER_STATIMPL_HPP
