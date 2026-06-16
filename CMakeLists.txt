# Set the minimum required version of CMake for modern features
cmake_minimum_required(VERSION 3.16)

# Define the project name, version, and primary programming language
project(FacialAuthentification VERSION 1.0 LANGUAGES CXX)

# Enforce C++17 standard compliance across all compilers
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configure compiler-specific warning and optimization flags
if(MSVC)
    # Strict warning level for Microsoft Visual Studio Compiler
    add_compile_options(/W4)
else()
    # Enable all standard warnings and performance optimizations for GCC/Clang
    add_compile_options(-Wall -Wextra -O2)
endif()

# ==============================================================================
# Dependency Management
# ==============================================================================
# Locate the required OpenCV 5 installation package on the host system
find_package(OpenCV 5 REQUIRED)

# ==============================================================================
# Target Definitions
# ==============================================================================
# Define the executable target and list all associated source implementation files
# Note: Header files (.h/.hpp) do not need to be listed; CMake tracks them automatically
add_executable(app 
    main.cpp 
    FaceDetector.cpp
    FaceRecognizer.cpp
)

# Link the executable with the required OpenCV libraries and include paths
target_link_libraries(app PRIVATE ${OpenCV_LIBS})