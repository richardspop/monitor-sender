//
// Created by Pop Richards on 27/12/20.
//

#include "CPUStatImpl.hpp"

CPUStatImpl::CPUStatImpl(std::string statSource) {
    // Check and create the Stats implementation based on source
    if (statSource == "procstat") {
        statImpl = new CPUProcStat();
        // Start monitoring, Needed for /proc/stats
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
    // Unsupported API
    std::cout << "Unsupported method CPUStatImpl::getMemoryUsage()" << std::endl;
}