#include "CurlDownloader.h"
#include <iostream>
#include <stdexcept> // Include the header for exceptions

CurlDownloader::CurlDownloader(CurlInterface *curlInterface)
    : curlInterface(curlInterface) {
  curl_global_init(CURL_GLOBAL_DEFAULT);
}

CurlDownloader::~CurlDownloader() { curl_global_cleanup(); }

size_t CurlDownloader::writeCallback(void *contents, size_t size, size_t nmemb,
                                     std::string *buffer) {
  size_t realsize = size * nmemb;
  buffer->append(static_cast<char *>(contents), realsize);
  return realsize;
}

std::string CurlDownloader::downloadFile(const std::string &url) {
  try {
    if (!curlInterface) {
      throw std::runtime_error("CurlInterface is null.");
    }

    if (url.empty()) {
      throw std::invalid_argument("Empty URL provided.");
    }

    CURL *curl = curl_easy_init();
    std::string downloadedData;

    if (curl) {
      curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &downloadedData);

      CURLcode res = curlInterface->curl_easy_perform(curl);

      if (res != CURLE_OK) {
        std::string errorMessage = "curl_easy_perform() failed: ";
        errorMessage += curl_easy_strerror(res);
        throw std::runtime_error(errorMessage);
      }

      curl_easy_cleanup(curl);
    } else {
      throw std::runtime_error("Failed to initialize curl.");
    }

    return downloadedData;
  } catch (const std::exception &ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
    // Handle the error, log it, or rethrow it based on your requirements
    throw; // Rethrow the exception after logging or handling it
  }
}
