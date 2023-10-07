#pragma once

#include <string>

class CurlInterface {
public:
  virtual ~CurlInterface() {}
  virtual CURLcode curl_easy_perform(CURL *curl) = 0;
  // Add other curl functions used by CurlDownloader class
};

class MockCurlInterface : public CurlInterface {
public:
  MOCK_METHOD1(curl_easy_perform, CURLcode(CURL *curl));
  // Mock other curl functions here
};
