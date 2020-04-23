// This file contains the struct definitions for the cache statistics
// By: Nick from CoffeeBeforeArch
// 4/15/2020

#ifndef CACHE_STATS
#define CACHE_STATS

#include <cstdint>

// Top-level statistics class
struct CacheStats {
  // Constructors/Destructors
  CacheStats();
  ~CacheStats() = default;

  // Statistics functionality methods
  void dump_stats() const;

  // Data members
  // Number of store hits
  uint64_t store_hits;
  
  // Number of load hits
  uint64_t load_hits;
  
  // Number of store accesses
  uint64_t store_accesses;
  
  // Number of load accesses
  uint64_t load_accesses;
  
  // Number of instructions
  uint64_t instructions;

  // Number of diry cache lines evicted
  uint64_t dirty_evictions;
};

#endif
