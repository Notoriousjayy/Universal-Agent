// Cross-Platform-Resource-Management.cpp

#include "Cross-Platform-Resource-Management.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
#include <cstdio>
#include <unistd.h>
#endif

void checkCPUUsage() {
// Platform-specific code to get CPU usage
// Windows
#if defined(_WIN32) || defined(_WIN64)
  FILETIME createTime, exitTime, kernelTime, userTime;
  GetProcessTimes(GetCurrentProcess(), &createTime, &exitTime, &kernelTime,
                  &userTime);
  SYSTEM_INFO sysInfo;
  GetSystemInfo(&sysInfo);
  ULARGE_INTEGER kernel, user;
  kernel.LowPart = kernelTime.dwLowDateTime;
  kernel.HighPart = kernelTime.dwHighDateTime;
  user.LowPart = userTime.dwLowDateTime;
  user.HighPart = userTime.dwHighDateTime;
  double cpuUsage = (kernel.QuadPart + user.QuadPart) /
                    (sysInfo.dwNumberOfProcessors * 10000000.0);

  printf("CPU Usage: %lf%%\n", cpuUsage);

// Unix-based systems (Linux, macOS)
#else
  FILE *file = fopen("/proc/stat", "r");
  unsigned long long user, nice, system, idle, iowait, irq, softirq;
  fscanf(file, "cpu %llu %llu %llu %llu %llu %llu %llu", &user, &nice, &system,
         &idle, &iowait, &irq, &softirq);
  fclose(file);

  unsigned long long totalCpuTime =
      user + nice + system + idle + iowait + irq + softirq;
  unsigned long long idleTime = idle + iowait;
  double cpuUsage = 100 * (totalCpuTime - idleTime) / totalCpuTime;

  printf("CPU Usage: %lf%%\n", cpuUsage);
#endif
}
