#pragma once

#include <curl/curl.h>
#include <string>

class CurlInterface {
public:
  virtual ~CurlInterface() {}
  virtual CURLcode curl_easy_perform(CURL *curl) = 0;
  // Add other curl functions used by CurlDownloader class
};

class CurlDownloader {
public:
  CurlDownloader(CurlInterface *curlInterface);
  ~CurlDownloader();
  std::string downloadFile(const std::string &url);

private:
  CurlInterface *curlInterface;
  static size_t writeCallback(void *contents, size_t size, size_t nmemb,
                              std::string *buffer);
};
