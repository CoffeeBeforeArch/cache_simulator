// This file contains the implementation of the cache set methods
// By: Nick from CoffeeBeforeArch
// 4/16/2020

#include "simulation.hh"
#include <iostream>
#include "access.hh"
#include "cache_config.pb.h"
#include "data_cache.hh"

// Constructor
// Initializes the cache level and cache access driver
// Fixed batch size of 8192 accesses
CacheSim::CacheSim(CacheConfig config)
    : CL(config), CA(1 << 13, config.trace_file_path()) {}

// Destructor
// Prints out the top-level sim stats
CacheSim::~CacheSim() {
  // Print out a few top-level stats that wouldn't be tracked by the caches
  // anyway
  std::cout << "INSTRUCTIONS\t" << instructions << '\n';
  std::cout << "CYCLES\t\t" << cycles << '\n';
}

void CacheSim::run() {
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
}
