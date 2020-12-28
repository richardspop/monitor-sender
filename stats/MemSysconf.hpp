//
// Created by Pop Richards on 28/12/20.
//

#ifndef MONITOR_SENDER_MEMSYSCONF_HPP
#define MONITOR_SENDER_MEMSYSCONF_HPP

#include "AbstractStatImplInterface.hpp"

#include <unistd.h>
#include <iostream>

#include "../nlohmann/json.hpp"

class MEMSysconf: public AbstractStatImplInterface {
public:
    MEMSysconf();
    std::string getStats();
    void StartMonitoring();
};


#endif //MONITOR_SENDER_MEMSYSCONF_HPP
