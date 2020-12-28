//
// Created by Pop Richards on 28/12/20.
//

#include "MemSysconf.hpp"

MEMSysconf::MEMSysconf() {
    std::cout << "Created MEM sysconf stat instance" << std::endl;
}

void MEMSysconf::StartMonitoring() {
    std::cout << "Nothing to monitor for sysconfig" << std::endl;
}

std::string MEMSysconf::getStats() {
    //std::cout << "GetStats mem usage" << std::endl;
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    long free_pages = sysconf(_SC_AVPHYS_PAGES);
    nlohmann::json j;
    j["mem"] = (pages - free_pages) * page_size;
    std::cout << "Called MEMSysconf::getStats() - " << j.dump() << std::endl;
    return j.dump();
}