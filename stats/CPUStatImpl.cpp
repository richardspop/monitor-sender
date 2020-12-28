//
// Created by Pop Richards on 27/12/20.
//

#include "CPUStatImpl.hpp"

CPUStatImpl::CPUStatImpl(std::string statSource) {
    if (statSource == "procstat") {
        statImpl = new CPUProcStat();
        statImpl->StartMonitoring();
    } else {
        std::cout << "Unsupported stats" << std::endl;
    }
    std::cout << "Created CPU stats impl instance" << std::endl;
}

std::string CPUStatImpl::getCPUUsage() {
    std::cout << "Called CPUStatImpl::getCPUUsage" << std::endl;
    return statImpl->getStats();
}

std::string CPUStatImpl::getMemoryUsage() {
    std::cout << "Unsupported method CPUStatImpl::getMemoryUsage()" << std::endl;
}