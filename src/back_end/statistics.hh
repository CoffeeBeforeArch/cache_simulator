// This file contains the struct definitions for the cache statistics
// By: Nick from CoffeeBeforeArch
// 4/15/2020

#include <cstdint>

// Top-level statistics class
struct CacheStats {
  // Constructors/Destructors
  CacheStats();
  ~CacheStats() = default;

  // Statistics functionality methods
  void dump_stats() const;

  // Data members
  // Cache Accesses
  uint64_t accesses;
  
  // Number of hits
  uint64_t hits;
  
  // Number of stores
  uint64_t stores;
  
  // Number of instructions
  uint64_t instructions;
};
