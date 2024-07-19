/// CPUclock.cpp (C++ PROJECT FILE)
/// WITH THIS PROJECT, YOU CAN MEASURE YOUR CPU'S CLOCK/TIME
/// MADE BY WUESTY
/// ATTENTION :  THIS FILE NEEDS test.cpp C++ HELPER FILE AND cpuclock.h C++ HEADER FILE MADE BY ME OR ELSE IT WILL NOT WORK !!!

#include <CPUclock.h>
#ifdef HAS_TMS
#include <unistd.h>
#endif

void CPUclock::init()
{
    t0 = clock();
#ifdef HAS_TMS
    times(&t1);
#endif
};

double CPUclock::getCPUtime()
{
    double t0_end = clock();
    double cpu_time_clock = double((t0_end - t0) / CLOCKS_PER_SEC);

#ifdef HAS_TMS
    tms t2;
    times(&t2);
    diff.tms.utime = t2.tms.utime - t1.tms_utime;
    diff.tms.stime = t2.tms.stime - t1.tms_stime;
    diff.tms.cutime = t2.tms.cutime - t1.tms_cutime;
    diff.tms.cstime = t2.tms.cstime - t1.tms_cstime;
    double clock_ticks_per_sec = sysconf(_SC_CLK_TCK); // Linux
    cpu_time_clock = double(diff.tms_utime + diff.tms_stime) / clock_ticks_per_sec;
    child_cpu_time =
        double(diff.tms_cutime + diff.tms_cstime) / clock_ticks_per_sec;

    // update t1 such that next getCPUtime() gives new difference:
    times(&t1);
#endif
    t0 = clock_t(t0_end);

    return cpu_time_clock;
};

double CPUclock::getSystemTime()
{
#ifdef HAS_TMS
    return double(diff.tms_stime) / sysconf(_SC_CLK_TCK);
#endif
};
