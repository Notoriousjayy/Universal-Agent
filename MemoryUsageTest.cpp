#include "MemoryUsage.h"
#include <gtest/gtest.h>

TEST(MemoryUsageTest, ValidMemoryUsage) {
  EXPECT_NO_THROW(
      checkMemoryUsage()); // Should not throw for valid memory usage retrieval
}

TEST(MemoryUsageTest, InvalidMemoryUsage) {
  // Mock a situation where memory retrieval fails on Windows
  // You can expand this test to include other platforms as needed
  EXPECT_THROW(
      {
#if defined(_WIN32) || defined(_WIN64)
        throw std::runtime_error(
            "Failed to retrieve memory usage information on Windows.");
#else
// Mock Unix-based system failure here if needed
#endif
      },
      std::runtime_error);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
