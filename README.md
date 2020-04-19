# Cache Simulator

This repository contains the source code for a simple trace-based cache simulator

## Motivation

I enjoy C++ programming and computer architecture. This repository serves as a fun side-project to help teach people about low-level hardware through high-level code. For some, this project may serve a useful guide for coursework (I know a lot of computer architecture classes require you to ). Personally, I hope to use the project to better understand memory systems and brainstorming ideas for efficient simulator designs.

## Contact Information

Questions may be sent to [CoffeeBeforeArch@gmail.com](CoffeeBeforeArch@gmail.com). If you find a bug, feel free to take out an issue, or make a pull request with a fix.

## Build Requirements / Instructions

## Latest Simulator Thoughts

### 4/17/2020

Made some progress on tying all the components together for the first time. While I originally was going to try and write a scanner+parser using a Flex and Bison, I have opted to use a Python frontend. I wrote some simple parsing code for a memory trace file I found online (as part of CS course cache simulator project). I think using this for verification will be a good first step. Until I decide to setup a python frontend I'm going to have a simple test app called driver which will configure
the simulator and run some tests. The python work should be done soon so I can integrate unit tests as early as possible. Next steps will be to drive the first simulation run, and verify functionality for an LRU replacement policy in a single level cache, collecting only basic stats (#hits, #stores, #accesses).

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

