//
// Created by Pop Richards on 27/12/20.
//

#ifndef MONITOR_SENDER_ABSTRACTSTATINTERFACE_HPP
#define MONITOR_SENDER_ABSTRACTSTATINTERFACE_HPP

#include <string>

// Interface to get stats from various sources
class AbstractStatInterface {
public:
    virtual std::string getCPUUsage() = 0;
    virtual std::string getMemoryUsage() = 0;
};


#endif //MONITOR_SENDER_ABSTRACTSTATINTERFACE_HPP
