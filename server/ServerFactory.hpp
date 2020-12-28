//
// Created by Pop Richards on 27/12/20.
//

#ifndef MONITOR_SENDER_SERVERFACTORY_HPP
#define MONITOR_SENDER_SERVERFACTORY_HPP


#include <string>

class ServerFactory {
public:
    virtual void Serve(std::string bindAddress, int statCollationTimer) = 0;
};


#endif //MONITOR_SENDER_SERVERFACTORY_HPP
