// This file contains the class definitions for the cache statistics
// By: Nick from CoffeeBeforeArch
// 4/15/2020

#include <cstdint>

// Top-level statistics class
class CacheStats {
 public:
  // Constructors/Destructors
  CacheStats();
  ~CacheStats();

  // Statistics functionality methods

 private:
  // Cache Accesses
  uint64_t accesses;
  // Number of hits
  uint64_t hits;
};
