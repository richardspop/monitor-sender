//
// Created by Pop Richards on 27/12/20.
//

#ifndef MONITOR_SENDER_ABSTRACTSTATIMPLINTERFACE_HPP
#define MONITOR_SENDER_ABSTRACTSTATIMPLINTERFACE_HPP

#include <string>

class AbstractStatImplInterface {
public:
    virtual std::string getStats() = 0;
    virtual void StartMonitoring() = 0;
};


#endif //MONITOR_SENDER_ABSTRACTSTATIMPLINTERFACE_HPP
