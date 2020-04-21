// This a simple driver for the simulator to test initial functionality
// By: Nick from CoffeeBeforeArch
// 4/17/2020

#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>
#include <tuple>
#include "../back_end/data_cache.hh"
#include "../front_end/access.hh"
#include "../pb/cacheConfig.pb.h"

// This driver is acting like a pseudo-core that probes the memory system with
// accesses
int main(int argc, char *argv[]) {
  // Kill if a file name isn't passed in
  assert(argc == 2);

  // Create a file
  std::string file_name(argv[1]);

  // Test our protobuf
  CacheConfig config;

  // Size of 2^16 - 64kB
  config.set_cache_size(1 << 16);

  // Line size of 2^5 = 32B
  config.set_line_size(1 << 5);

  // Associativity of 8 (8-way set associative cache)
  config.set_associativity(8);

  // Miss penalty is 42 cycles
  config.set_miss_penalty(42);

  // Create our cache based on our config
  CacheLevel CL(config);

  // Create our cache access object
  // Instruction batch size of 2^13 (8k) (Just read in the whole thing?)
  CacheAccess CA(1 << 13, file_name);

  // Count the number of instructions and reported cycles
  uint64_t cycles = 0;
  uint64_t instructions = 0;

  // Get a new batch of accesses
  size_t accesses = CA.fetch_access_batch();

  // Continue until we run out of accesses
  while (accesses) {
    for (size_t i = 0; i < accesses; i++) {
      // Get the address, # in-between instructions, and type (L/S)
      auto [addr, insn, type] = CA.get_access();
      
      // Increment the number of instructions
      instructions += insn;

      // Probe the cache
      // Add the cycles for the memory access plus 1 for each instruction
      cycles += CL.probe(addr, type) + insn;
    }

    // Try and fetch some more instructions from the file
    accesses = CA.fetch_access_batch();
  }

  // Print out a few top-level stats that wouldn't be tracked by the caches
  // anyway
  std::cout << "INSTRUCTIONS\t" << instructions << '\n';
  std::cout << "CYCLES\t\t" << cycles << '\n';

  return 0;
}
