// This file contains the struct definitions for the cache statistics
// By: Nick from CoffeeBeforeArch
// 4/15/2020

#include <cstdint>

// Top-level statistics class
struct CacheStats {
  // Constructors/Destructors
  CacheStats();
  ~CacheStats();

  // Statistics functionality methods

  // Data members
  // Cache Accesses
  uint64_t accesses;
  // Number of hits
  uint64_t hits;
};
