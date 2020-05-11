// This file contains the class definitions for the data cache
// By: Nick from CoffeeBeforeArch
// 4/15/2020

#ifndef DATA_CACHE
#define DATA_CACHE

#include <cstdint>
#include <vector>
#include "cache_config.pb.h"
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
  uint32_t probe(uint64_t addr, bool type);

  // Replace a cache line
  void replace_line(uint64_t addr);

 private:
  // Structure of statistics for each cache
  CacheStats stats = CacheStats();

  // Vector of cache line starting addresses
  std::vector<CacheSet> sets;

  // Associativity of the cache
  const uint64_t num_sets;

  // Line size of the cache
  const uint32_t line_size;
  
  // Miss penalty of the cache
  const uint32_t miss_penalty;
};

#endif
