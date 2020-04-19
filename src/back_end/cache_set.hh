// This file contains the class definitions for the data cache
// By: Nick from CoffeeBeforeArch
// 4/16/2020

#include <cstdint>
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
  bool probe(uint64_t addr);
  // Replace a cache line in the set
  void replace_line(uint64_t addr);

 private:
  // Data members
  // A set of cache lines
  // Only the starting address for each cache line is stored
  std::vector<uint64_t> lines;
  // Priority of each line in the set
  // Used for the replacement policy
  std::vector<unsigned> priority;
  // Mask of unused cache lines in the set
  // Optimization while sets are still empty
  std::vector<bool> set_mask;
};
