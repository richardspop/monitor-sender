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
    //timer_start(UpdateCPUStats, 1);
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

    ifstream statFile(procStatPath);

    if (statFile.good()) {
        getline(statFile, procStat);
    }
    statFile.close();

    istringstream iss(procStat);

    while (getline(iss, temp, ' ')) {
        vStats.push_back(temp);
    }

//    cout << "print Vector" << endl;
//    for(int i = 0; i < vStats.size(); i++) {
//        cout << vStats[i] << endl;
//    }

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

    unsigned long currWorkTicks = std::stoi(vStats[USER_TICK]) +
                                  std::stoi(vStats[NICE_TICK]) +
                                  std::stoi(vStats[SYS_TICK]);

    unsigned long prevTotalTicks = totalTicks;
    unsigned long prevWorkTicks = workTicks;

    totalTicks = currTotalTicks;
    workTicks = currWorkTicks;

    if (prevTotalTicks > currTotalTicks) {
        cout << "CPU totalTicks looped" << endl;
        currTotalTicks += prevTotalTicks;
    }
    if (prevWorkTicks > currWorkTicks) {
        cout << "CPU workTicks looped" << endl;
        currWorkTicks += prevWorkTicks;
    }

    if (prevTotalTicks == 0 && prevWorkTicks == 0) {
        cout << "First time update" << endl;
    } else {
        //cout << currWorkTicks << ", " << prevWorkTicks << ", " << currTotalTicks << ", " << prevTotalTicks << endl;
        cpu = ( (float) (currWorkTicks - prevWorkTicks) / (float) (currTotalTicks - prevTotalTicks) ) * 100;
    }

    j["cpu"] = cpu;
    cpuStats = j.dump();
    //cout << "updating cpuStats - " << cpuStats << endl;

}