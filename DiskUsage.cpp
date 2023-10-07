#include "DiskUsage.h"
#include <boost/filesystem.hpp>
#include <iostream>
#include <stdexcept> // Include the header for exceptions

void checkDiskUsage() {
  try {
    // Cross-platform code to get disk usage
    boost::filesystem::space_info diskSpace = boost::filesystem::space("/");
    if (diskSpace.free == 0) {
      throw std::runtime_error(
          "Disk space is not available."); // Throw a custom exception
    }
    std::cout << "Free Disk Space: " << diskSpace.free << " bytes\n";
  } catch (const std::exception &ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
    // Handle the error, log it, or throw it again based on your requirements
  }
}
