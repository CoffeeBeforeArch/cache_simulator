// This a simple driver for the simulator to test initial functionality
// By: Nick from CoffeeBeforeArch
// 4/17/2020

#include <cassert>
#include <cstdint>
#include <string>
#include <tuple>
#include "access.hh"
#include "cacheConfig.pb.h"
#include "data_cache.hh"
#include "simulation.hh"

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

  // Set the trace file path
  config.set_trace_file_path(file_name);

  // Create the simulator and run
  CacheSim sim(config);
  sim.run();

  return 0;
}
