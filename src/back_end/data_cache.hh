// This file contains the class definitions for the data cache
// By: Nick from CoffeeBeforeArch
// 4/15/2020

#include <cstdint>
#include <vector>
#include "../pb/cacheConfig.pb.h"
#include "statistics.hh"

// Top-level cache class
class CacheLevel {
 public:
  // Constructors/Destructors
  CacheLevel(CacheConfig config);
  ~CacheLevel();

  // Cache functionality methods
  void probe(uint64_t addr);

 private:
  // Structure of statistics for each cache
  CacheStats stats = CacheStats();

  // Vector of cache line starting addresses
  std::vector<uint64_t> lines;

  // Associativity of the cache
  const int ways;
};

