#include "Cross-Platform-Resource-Management.h"
#include "CurlDownloader.h"
#include "DiskUsage.h"
#include "MemoryUsage.h"

// Include unistd.h for sleep function on Unix-based systems
#ifndef _WIN32
#include <unistd.h>
#endif

int main() {
  const std::string fileUrl =
      "https://example.com/file.txt"; // Replace with the actual file URL

  while (1) {
    // Check CPU Usage
    checkCPUUsage();

// Platform-independent sleep function
#if defined(_WIN32) || defined(_WIN64)
    Sleep(1000); // Sleep for 1 second on Windows
#else
    sleep(1); // Sleep for 1 second on Unix-based systems
#endif

    // Download File
    CurlDownloader downloader;
    std::string downloadedData = downloader.downloadFile(fileUrl);

    std::cout << "Downloaded Data:\n" << downloadedData << std::endl;

    // Check Memory and Disk Usage
    checkMemoryUsage();
    checkDiskUsage();
  }

  return 0;
}
