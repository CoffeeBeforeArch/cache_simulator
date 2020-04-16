// This file contains the implementation of the data cache methods
// By: Nick from CoffeeBeforeArch
// 4/15/2020

#include "data_cache.hh"
#include <cstdint>
#include "../pb/cacheConfig.pb.h"

// Constructor
CacheLevel::CacheLevel(CacheConfig config) : ways(config.associativity()) {
  // Allocate and initialize the cache
  // We only store the starting address for each cache line
  // Addresses are contiguous!
  lines.resize(config.cache_size() / config.line_size());
}

// Probe this level of the cache using the address
void CacheLevel::probe(uint64_t) {
  
}
