//
// Created by Pop Richards on 28/12/20.
//

#include "MemStatImpl.hpp"

MEMStatImpl::MEMStatImpl(std::string statSource) {
    // Check and create the Stats implementation based on source
    if (statSource == "sysconf") {
        statImpl = new MEMSysconf();
    } else {
        std::cout << "Unsupported stats" << std::endl;
    }
    std::cout << "Created MEM stats impl instance" << std::endl;
}

std::string MEMStatImpl::getCPUUsage() {
    // Unsupported API
    std::cout << "Unsupported method MEMStatImpl::getCPUUsage()" << std::endl;
}

std::string MEMStatImpl::getMemoryUsage() {
    std::cout << "Called MEMStatImpl::getMemoryUsage" << std::endl;
    return statImpl->getStats();
}