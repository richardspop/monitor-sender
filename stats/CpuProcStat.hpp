//
// Created by Pop Richards on 27/12/20.
//

#ifndef MONITOR_SENDER_CPUPROCSTAT_HPP
#define MONITOR_SENDER_CPUPROCSTAT_HPP

#include "AbstractStatImplInterface.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <thread>
#include <functional>
#include <string>
#include "../nlohmann/json.hpp"

class CPUProcStat: public AbstractStatImplInterface{
private:
    std::string procStatPath = "/proc/stat";
    std::string cpuStats = "";

    unsigned long totalTicks = 0;
    unsigned long workTicks = 0;

    // Stats in /proc/stat are ordered with the below constant spacing.
    // More info : https://linux.die.net/man/5/proc
    const unsigned int USER_TICK = 2;
    const unsigned int NICE_TICK = 3;
    const unsigned int SYS_TICK = 4;
    const unsigned int IDLE_TICK = 5;
    const unsigned int IO_TICK = 6;
    const unsigned int IRQ_TICK = 7;
    const unsigned int SIRQ_TICK = 8;
    const unsigned int STEAL_TICK = 9;
    const unsigned int GUEST_TICK = 10;
    const unsigned int GUEST_NICE_TICK = 11;


    void UpdateCPUStats();
public:
    CPUProcStat();
    std::string getStats();
    void StartMonitoring();
};


#endif //MONITOR_SENDER_CPUPROCSTAT_HPP
