// This file contains the class definitions for the data cache
// By: Nick from CoffeeBeforeArch
// 4/16/2020

#include <cstdint>
#include <vector>
#include "../pb/cacheConfig.pb.h"
#include "replacement_policy.hh"

// Top-level cache class
class CacheSet {
 public:
  // Constructors/Destructors
  CacheSet(int ways);
  ~CacheSet() = default;

  // Set functionality methods
  // Look up an address in the cache set
  bool probe(uint64_t addr);

  // Replace a cache line in the set and return where it was stored
  int replace_line(uint64_t addr);

  // Update the priority of the cache line
  void update_priority(int latest_line);

 private:
  // Data members
  // A set of cache lines
  // Only the starting address for each cache line is stored
  std::vector<uint64_t> lines;

  // Number of open lines in the set
  unsigned used_lines = 0;

  std::vector<unsigned> priority;
  // Class containing logic for the replacement policy
  //ReplacementPolicy policy;
};
