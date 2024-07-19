/// test.cpp (C++ PROJECT HELPER FILE)
/// MADE BY WUESTY
/// ATTENTION :  THIS IS THE FILE THAT HELPS RUNNING cpuclock.cpp AND IT NEEDS cpuclock.h TO WORK !!!

#include <CPUclock.h>

int main() {

    clock_t t0 = clock();
    clock_t t1 = clock();
    double cpu_time = (t1 - t0) / CLOCKS_PER_SEC;

    double cpu_time0;
    double cpu_time1;
    double cpu_time2;
    
    CPUclock clock;
    clock.init();
    
    cpu_time0 = clock.getCPUtime();
    cpu_time1 = clock.getCPUtime();
    cpu_time2 = clock.getCPUtime();

    return 0;
}
 