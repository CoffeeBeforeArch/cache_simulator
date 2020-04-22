// This file contains the class definitions for the data cache
// By: Nick from CoffeeBeforeArch
// 4/16/2020

#ifndef CACHE_SET
#define CACHE_SET

#include <cstdint>
#include <tuple>
#include <vector>
#include "../pb/cacheConfig.pb.h"

// Top-level cache class
class CacheSet {
 public:
  // Constructors/Destructors
  CacheSet(int ways);
  ~CacheSet() = default;

  // Set functionality methods
  // Look up an address in the cache set
  std::tuple<bool, bool> probe(uint64_t addr, bool type);

  // Replace a cache line in the set and return where it was stored
  uint32_t replace_line(uint64_t addr);

  // Update the priority of the cache line
  void update_priority(uint32_t latest_line);

  // Update the dirty state of the cache line
  bool update_dirty_state(uint32_t latest_line, bool type, bool hit);

 private:
  // Data members
  // A set of cache lines
  // Only the starting address for each cache line is stored
  std::vector<uint64_t> lines;

  // Number of open lines in the set
  uint32_t used_lines = 0;

  // Replacement policy priorities
  // Lower = Better
  std::vector<uint32_t> priority;

  // Dirty cache line bits
  std::vector<bool> dirty_bits;
};

#endif
