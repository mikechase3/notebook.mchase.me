Add this to a cmake file:

```
cmake_minimum_required(VERSION 3.27)
project(AS02_BeizerCurves)

set(CMAKE_CXX_STANDARD 17)
set(OpenCV_DIR /opt/homebrew/Cellar/opencv)
find_package(OpenCV REQUIRED)

# Add OpenCV Header Files to Project
include_directories(${OpenCV_INCLUDE_DIRS})

# Add a subdirectory to the build; (requires utils folder & CmakeLists.txt)
    # add_subdirectory(utils)

# Add optional log with a precompiler definition
option(WITH_LOG "Build with output logs and images in tmp" OFF)
if(WITH_LOG)
    add_definitions(-DLOG)
endif(WITH_LOG)

# Generate New Executable
add_executable(${PROJECT_NAME} main.cpp)

# Link project with ependencies
target_link_libraries(AS02_BeizerCurves ${OpenCV_LIBS})

```