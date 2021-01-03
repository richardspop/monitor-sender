//
// Created by Pop Richards on 27/12/20.
//

#include "CpuProcStat.hpp"

CPUProcStat::CPUProcStat() {
    std::cout << "Created CPU proc stat instance" << std::endl;
}

std::string CPUProcStat::getStats() {
    std::cout << "Called CPUProcStat::getStats() - " << cpuStats << std::endl;
    return cpuStats;
}

void CPUProcStat::StartMonitoring() {
    std::cout << "Monitoring started" << std::endl;
    // Lambda function to start monitoring /proc/stat stats.
    auto f = [this](int interval) {
        while (true) {
            UpdateCPUStats();
            std::this_thread::sleep_for(std::chrono::seconds(interval));
        }
    };

    std::thread(f, 1).detach();
}

void CPUProcStat::UpdateCPUStats() {
    using namespace std;

    string procStat;
    vector<string> vStats;
    string temp;
    float cpu;
    nlohmann::json j;

    // Read from /proc/stat
    ifstream statFile(procStatPath);

    if (statFile.good()) {
        getline(statFile, procStat);
    }
    statFile.close();

    istringstream iss(procStat);

    while (getline(iss, temp, ' ')) {
        vStats.push_back(temp);
    }

    // Current ticks = total of all ticks in the system
    unsigned long currTotalTicks = std::stoi(vStats[USER_TICK]) +
                                   std::stoi(vStats[NICE_TICK]) +
                                   std::stoi(vStats[SYS_TICK]) +
                                   std::stoi(vStats[IDLE_TICK]) +
                                   std::stoi(vStats[IO_TICK]) +
                                   std::stoi(vStats[IRQ_TICK]) +
                                   std::stoi(vStats[SIRQ_TICK]) +
                                   std::stoi(vStats[STEAL_TICK]) +
                                   std::stoi(vStats[GUEST_TICK]) +
                                   std::stoi(vStats[GUEST_NICE_TICK]);

    // CPU usage = total of ticks from user, process and system
    unsigned long currWorkTicks = std::stoi(vStats[USER_TICK]) +
                                  std::stoi(vStats[NICE_TICK]) +
                                  std::stoi(vStats[SYS_TICK]);

    // The ticks in /proc/stats are only current usage. to identify change,
    // we need historical values. so storing current values for next calculation
    unsigned long prevTotalTicks = totalTicks;
    unsigned long prevWorkTicks = workTicks;

    totalTicks = currTotalTicks;
    workTicks = currWorkTicks;

    // the stats are int values and can rotate over INT_MAX
    // Handling the rotation can be performed with long values
    if (prevTotalTicks > currTotalTicks) {
        cout << "CPU totalTicks looped" << endl;
        currTotalTicks += prevTotalTicks;
    }
    if (prevWorkTicks > currWorkTicks) {
        cout << "CPU workTicks looped" << endl;
        currWorkTicks += prevWorkTicks;
    }

    // We need at least 1 historical data to calculate cpu usage.
    if (prevTotalTicks == 0 && prevWorkTicks == 0) {
        cout << "First time update" << endl;
    } else {
        // Since we are taking percentile, no need to convert ticks to seconds.
        // Calculating the cpu usage over the give monitoring time.
        //cout << currWorkTicks << ", " << prevWorkTicks << ", " << currTotalTicks << ", " << prevTotalTicks << endl;
        cpu = ( (float) (currWorkTicks - prevWorkTicks) / (float) (currTotalTicks - prevTotalTicks) ) * 100;
    }

    // Update cpu usage
    j["cpu"] = cpu;
    cpuStats = j.dump();
}