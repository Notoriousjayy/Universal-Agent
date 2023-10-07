#include "CurlDownloader.h"
#include <gtest/gtest.h>

class MockCurlInterface : public CurlInterface {
public:
  CURLcode curl_easy_perform(CURL *curl) override {
    // Mock implementation for curl_easy_perform
    // Return CURLE_OK to simulate a successful download
    return CURLE_OK;
  }
};

TEST(CurlDownloaderTest, NullCurlInterface) {
  // Arrange
  CurlDownloader downloader(nullptr);

  // Act & Assert
  ASSERT_THROW(downloader.downloadFile("https://example.com"),
               std::runtime_error);
}

TEST(CurlDownloaderTest, EmptyURL) {
  // Arrange
  MockCurlInterface mockCurl;
  CurlDownloader downloader(&mockCurl);

  // Act & Assert
  ASSERT_THROW(downloader.downloadFile(""), std::invalid_argument);
}

TEST(CurlDownloaderTest, SuccessfulDownload) {
  // Arrange
  MockCurlInterface mockCurl;
  CurlDownloader downloader(&mockCurl);

  // Act
  std::string downloadedData = downloader.downloadFile("https://example.com");

  // Assert
  ASSERT_FALSE(downloadedData.empty());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
