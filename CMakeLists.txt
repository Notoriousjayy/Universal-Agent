cmake_minimum_required(VERSION 3.0)
project(MyProject)

# Set C++ standard (for example, C++11)
set(CMAKE_CXX_STANDARD 11)

# Find Boost
find_package(Boost REQUIRED COMPONENTS filesystem system)

# Add your source files
set(SOURCES 
    Cross-Platform-Resource-Management.cpp
    MemoryUsage.cpp
    DiskUsage.cpp
    main.cpp
)

# Create an executable from the source files
add_executable(myprogram ${SOURCES})

# Include Boost headers
target_include_directories(myprogram PRIVATE ${Boost_INCLUDE_DIRS})

# Link Boost libraries
target_link_libraries(myprogram ${Boost_LIBRARIES})
