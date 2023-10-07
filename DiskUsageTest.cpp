#include "DiskUsage.h"
#include <gtest/gtest.h>

TEST(DiskUsageTest, DiskSpaceAvailable) {
  // Arrange & Act
  try {
    checkDiskUsage();
    // If no exception is thrown, the test passes
    SUCCEED();
  } catch (const std::exception &ex) {
    // Assert
    FAIL() << "Unexpected exception: " << ex.what();
  }
}

TEST(DiskUsageTest, DiskSpaceNotAvailable) {
  // Arrange
  boost::filesystem::space_info zeroDiskSpace(0, 0, 0);

  // Mock the boost::filesystem::space function to return zero disk space
  boost::filesystem::space_function = [=](const boost::filesystem::path &) {
    return zeroDiskSpace;
  };

  // Act & Assert
  ASSERT_THROW(checkDiskUsage(), std::runtime_error);
}

TEST(DiskUsageTest, ValidFilesystem) {
  EXPECT_NO_THROW(
      checkDiskUsage("/")); // Check the root file system, should not throw
                            // Add more valid file systems for testing
}

TEST(DiskUsageTest, InvalidFilesystem) {
  EXPECT_THROW(checkDiskUsage("/nonexistentfilesystem"),
               std::runtime_error); // Nonexistent file system, should throw
                                    // Add more invalid file systems for testing
}

TEST(DiskUsageTest, FullFilesystem) {
  EXPECT_THROW(checkDiskUsage("/fullfilesystem"),
               std::runtime_error); // Full file system, should throw
                                    // Add more full file systems for testing
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
