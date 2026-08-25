``` markdown
# The C Programming Language Exercises

This repository contains solutions and tests for exercises from **The C Programming Language** by Brian W. Kernighan and Dennis M. Ritchie.

The project is written in **C** and uses:

- **CMake** as the build system
- **CTest** for running tests
- **Unity** as the C unit testing framework

## Project Structure

```
c_programming_language/ 
├── CMakeLists.txt 
├── README.md 
├── external/ 
│ └── unity/ 
└── chapter-1/ 
    └── exercise-1-1/ 
        ├── CMakeLists.txt 
        ├── exercise_1_1.c 
        ├── exercise_1_1.h 
        └── test_exercise_1_1.c
```text

``` 
Each exercise is kept in its own module directory.

## Requirements

Install the following tools:

- C compiler, for example `gcc` or `clang`
- CMake
- Git

Example on Ubuntu:
```bash
sudo apt update sudo apt install build-essential cmake git

git clone --recurse-submodules <repository-url> cd c_programming_language
```

If the repository was already cloned without submodules, initialize them manually:

```bash
git submodule update --init --recursive
```


## Configure the Project

Create a separate build directory:
```bash
cmake -S . -B cmake-build-debug```
```

For a debug build, use:

```bash
cmake -S . -B cmake-build-debug -DCMAKE_BUILD_TYPE=Debug
``` 

## Build the Project

Build all modules and tests:
```bash 
cmake --build cmake-build-debug
```

## Run All Tests

Run all registered tests from the build directory:
```bash 
ctest --test-dir cmake-build-debug
``` 

To see detailed output from failing tests:
```bash 
ctest --test-dir cmake-build-debug --output-on-failure
```

## Run Tests for a Specific Module

For example, to run only the test for `exercise-1-1`:
```bash 
ctest --test-dir cmake-build-debug -R test_exercise_1_1 --output-on-failure
``` 

You can also run the generated test executable directly:
```bash 
./cmake-build-debug/chapter-1/exercise-1-1/test_exercise_1_1
```

### Example Source File
```c 
#include "exercise_1_2.h"
void exercise_1_2_function(void) { /* implementation */ }
``` 

### Example Header File
```c 
#pragma once
void exercise_1_2_function(void);
```

### Example Test File
```c 
#include "exercise_1_2.h" #include "unity.h"
void setUp(void) { }
void tearDown(void) { }
void test_exercise_1_2_function(void) { exercise_1_2_function(); }
int main(void) { UNITY_BEGIN();
RUN_TEST(test_exercise_1_2_function);

return UNITY_END();
}
``` 

### Example Module CMakeLists.txt
```cmake 
add_library(exercise_1_2 exercise_1_2.c )
target_include_directories(exercise_1_2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )
add_executable(test_exercise_1_2 test_exercise_1_2.c )
target_link_libraries(test_exercise_1_2 exercise_1_2 unity )
add_test(NAME test_exercise_1_2 COMMAND test_exercise_1_2)
```

### Register the New Module

After creating the new exercise directory, register it in the root `CMakeLists.txt`:
```cmake 
add_subdirectory(chapter-1/exercise-1-2)
``` 

Then reconfigure and rebuild:
```bash 
cmake -S . -B cmake-build-debug cmake --build cmake-build-debug ctest --test-dir cmake-build-debug --output-on-failure
```

## Add a New Chapter

For a new chapter, create a new directory such as:
```text 
chapter-2/ 
└── exercise-2-1/ 
    ├── CMakeLists.txt 
    ├── exercise_2_1.c 
    ├── exercise_2_1.h 
    └── test_exercise_2_1.c``` 

Then add the exercise directory to the root `CMakeLists.txt`:
```cmake 
add_subdirectory(chapter-2/exercise-2-1)
```

## Naming Convention

Use consistent names for files, targets, and tests.

For exercise `chapter-X/exercise-X-Y`, prefer:
```text 
exercise_X_Y.c exercise_X_Y.h test_exercise_X_Y.c
``` 

CMake targets:
```text 
exercise_X_Y test_exercise_X_Y
```

CTest name:
```text 
test_exercise_X_Y
``` 

Example:
```text 
chapter-1/exercise-1-1/ 
    ├── exercise_1_1.c 
    ├── exercise_1_1.h 
    └── test_exercise_1_1.c
```

## Clean Build

To remove the build directory and start again:
```bash 
rm -rf cmake-build-debug cmake -S . -B cmake-build-debug cmake --build cmake-build-debug ctest --test-dir cmake-build-debug --output-on-failure
```