# monitor-sender
## stats
This is the stats library
this is used to create stat instance from different sources
It is used to obtain various usage stats such as cpu, memory, HDD, network, etc.,.
Adapter design pattern is used to manage all the various configuration of resources.

### AbstractStatInterface
This is part of Adapter design pattern to align the way stats are obtained. 
This provides an interface for getting stats.

### CPUStatImpl
CPUStatImpl inherits AbstractStatInterface. This maintains various sources for getting CPU stats
The Source from which we are going to get the CPU stat is configured from the constructor variable.
Multiple instance of CPUStatImpl can be created for multiple cpu stat sources. 

### MEMStatImpl
MEMStatImpl inherits AbstractStatInterface. This maintains various sources for getting memory stats
The Source from which we are going to get the memory stat is configured from the constructor variable.
Multiple instance of MEMStatImpl can be created for multiple memory stat sources.

### AbstractStatImplInterface
This is part of adapter design pattern to align the various Stat implementation. 
This provides an interface for implementing query of various stats

### CPUProcStat
CPUProcStat inherits AbstractStatImplInterface.
CPUProcStat queries the file /proc/stat in linux to calculate the percentile of CPU usage.
More info: https://linux.die.net/man/5/proc

### MEMSysconfImpl
MEMSysconfImpl inherits AbstractStatImplInterface.
MEMSysconfImpl queries the system library sysconf in linux to get the memory information and caluculate the memory usage.
More info: https://linux.die.net/man/3/sysconf

### Class Diagram
![Class Diagram](monitor_sender_stats_class.png?raw=true "Title")

### Sequence Diagram
![Sequence Diagram](monitor_sender_stats_sequence.png?raw=true "Title")