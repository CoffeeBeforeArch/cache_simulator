// This file contains the class definitions for the data cache
// By: Nick from CoffeeBeforeArch
// 4/15/2020

#include <cstdint>
#include <vector>
#include "../pb/cacheConfig.pb.h"
#include "cache_set.hh"
#include "statistics.hh"

// Top-level cache class
class CacheLevel {
 public:
  // Constructors/Destructors
  CacheLevel(CacheConfig config);
  ~CacheLevel();

  // Cache functionality methods
  // Probe the cache for an address
  void probe(uint64_t addr, bool type);

  // Handle a write access (separate early to help correlate branches?)
  bool handle_write(uint64_t addr);

  // Handle a read access (separate early to help correlate branches?)
  bool handle_read(uint64_t addr);
  
  // Replace a cache line
  void replace_line(uint64_t addr);

 private:
  // Structure of statistics for each cache
  CacheStats stats = CacheStats();

  // Vector of cache line starting addresses
  std::vector<CacheSet> sets;

  // Associativity of the cache
  const int ways;

  const int way_size;
};

