# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura Diseño y Análisis de Algoritmos
#
# @author Pablo Pérez González
# @date Febrero 2022
# @brief General CMakeLists.txt
#
# Build process:
#   1. cd <project_folder>
#   2. mkdir build
#   3. cd build
#   4. cmake ..
#   5. make


cmake_minimum_required(VERSION 3.1)  # Mandatory

# set the project name 
project(RAMMachineSimulator
    VERSION 1.0
    DESCRIPTION "A simulator of a RAM Machine"
    LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17) 						# Use c++17
set(CMAKE_CXX_STANDARD_REQUIRED True)

                            # If using gtest
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -pedantic -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/include)

                                    # If using tests
# Adds an executable target called "runTests" to be built from the source files listed in the command invocation.
add_executable(runTests                                                        # CHANGE
    test/gtest_main.cc                                                         # NO CHANGE
    include/my_vector.h                                                        # CHANGE
    src/my_vector.cc                                                           # CHANGE
    test/test_my_vector.cc)                                                    # CHANGE

# Adds an executable target called "main" to be built from the source files listed in the command invocation.
add_executable(main                                                            # CHANGE
    include/my_vector.h                                                        # CHANGE
    src/my_vector.cc                                                           # CHANGE
		src/main.cc)                                                               # CHANGE

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)                     # CHANGE

# Add expected compiler features to a target.
target_compile_features(runTests PRIVATE cxx_std_17)                           # CHANGE

# Add compile options to a target.
target_compile_options(runTests PRIVATE -Wall -Wextra -Wpedantic -Weffc++)     # CHANGE
target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic -Weffc++)         # CHANGE