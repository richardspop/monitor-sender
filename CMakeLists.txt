cmake_minimum_required(VERSION 3.17)
project(monitor_sender)

set(CMAKE_CXX_STANDARD 17)

find_package(cppzmq)

add_executable(monitor_sender main.cpp server/ServerFactory.hpp server/ZmqServer.cpp server/ZmqServer.hpp server/ServerFactoryImpl.cpp server/ServerFactoryImpl.hpp stats/AbstractStatInterface.hpp stats/AbstractStatImplInterface.hpp stats/CPUStatImpl.cpp stats/CPUStatImpl.hpp stats/CpuProcStat.cpp stats/CpuProcStat.hpp nlohmann/json.hpp stats/MemStatImpl.cpp stats/MemStatImpl.hpp stats/MemSysconf.cpp stats/MemSysconf.hpp)

target_link_libraries(monitor_sender cppzmq)