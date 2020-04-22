# Cache Simulator

This repository contains the source code for a simple trace-based cache simulator

## Motivation

I enjoy C++ programming and computer architecture. This repository serves as a fun side-project to help teach people about low-level hardware through high-level code. For some, this project may serve a useful guide for coursework (I know a lot of computer architecture classes require you to ). Personally, I hope to use the project to better understand memory systems and brainstorming ideas for efficient simulator designs.

## Contact Information

Questions may be sent to [CoffeeBeforeArch@gmail.com](CoffeeBeforeArch@gmail.com). If you find a bug, feel free to take out an issue, or make a pull request with a fix.

## Build Requirements / Instructions

## Latest Simulator Thoughts

### 4/21/2020
Matching results to the university project I'm consuming traces from! wrapped the simulator componenets inside of a CacheSim class. `driver.cpp` now just creates the simulator and calls run. Not terribly happy with instructions and cycles being separated from the other stats, however, those aren't really stats of the cache. Major remaining work would be to have a pytest frontent, and finish the build system. Then I would need to think about multiple frontends to test traces from different projects etc.

## Current Development Status

Here are the current parts of the simulator under active developement:

- Build System (in-progress)
  - Using CMake for the project (in-progress)
  - Regression tests (pending)
    - Performance (pending)
    - Functionality (pending)
- Front End (in-progress)
  - Trace consumption (in-progress)
  - Trace generator (pending)
  - On-the-fly generation (pending)
- Back End (in-progress)
  - Extendible cache structure (in-progress)
    - Basic caches (in-progress)
    - Cache sets (in-progress)
  - Statistics (in-progress)
    - Collection (in-progress)
    - Visualization (pending)

## Major Features

The core functionality of the simulator will be to consume a trace of memory accesses, and return a number of statistics (number of loads, number of stores, hit-rate, etc.). However, there are additional features that would be fun to support. The following are just some.

- Hierarchical caches
- Data cache optimizations (e.g. skewed associativity)
- Address translation (e.g., TLBs)
- Instruction cache optimizations (e.g. trace cache)
- Prefetchers
- Coherence
- Multiple replacement policies

