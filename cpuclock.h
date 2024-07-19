/// cpuclock.cpp (C++ HEADER FILE)
/// MADE BY WUESTY
/// ATTENTION :  THIS IS THE HEADER FILE THAT HELPS RUNNING test.cpp AND cpuclock.cpp

#ifndef CPUclock_H
#define CPUclock_H
#include <time.h> // clock function

#ifdef HAS_TMS
#include <sys/times.h> // tms struct
#endif

class CPUclock
{
private:
 clock_t t0;

#ifdef HAS_TMS
 tms t1, diff;
 double cpu_time, child_cpu_time;
#endif

public:
 void init();
 double getCPUtime();
 double getSystemTime();
};

#endif 