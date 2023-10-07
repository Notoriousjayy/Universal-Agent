#include "MemoryUsage.h"
#include <iostream>
#include <stdexcept> // Include the header for exceptions

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
#include <sys/sysinfo.h>
#endif

void checkMemoryUsage() {
  try {
// Platform-specific code to get memory usage
// Windows
#if defined(_WIN32) || defined(_WIN64)
    PROCESS_MEMORY_COUNTERS_EX pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(),
                             (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc))) {
      SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;
      std::cout << "Virtual Memory Used: " << virtualMemUsedByMe << " bytes\n";
    } else {
      throw std::runtime_error(
          "Failed to retrieve memory usage information on Windows.");
    }
// Unix-based systems (Linux, macOS)
#else
    struct sysinfo memInfo;
    if (sysinfo(&memInfo) != -1) {
      long long totalVirtualMem = memInfo.totalram;
      totalVirtualMem += memInfo.totalswap;
      totalVirtualMem *= memInfo.mem_unit;
      long long virtualMemUsed = memInfo.totalram - memInfo.freeram;
      virtualMemUsed += memInfo.totalswap - memInfo.freeswap;
      virtualMemUsed *= memInfo.mem_unit;
      std::cout << "Virtual Memory Used: " << virtualMemUsed << " bytes\n";
    } else {
      throw std::runtime_error(
          "Failed to retrieve memory usage information on Unix-based system.");
    }
#endif
  } catch (const std::exception &ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
    // Handle the error, log it, or rethrow it based on your requirements
  }
}
