// This file contains the implementation of the data cache methods
// By: Nick from CoffeeBeforeArch
// 4/15/2020

#include "data_cache.hh"
#include <algorithm>
#include <cstdint>
#include "../pb/cacheConfig.pb.h"

// Constructor
CacheLevel::CacheLevel(CacheConfig config) : ways(config.associativity()) {
  // Get the number of sets in the cache
  const auto num_sets =
      config.cache_size() / config.line_size() / config.associativity();

  // Allocate and initialize the cache
  std::fill_n(std::back_inserter(sets), num_sets, CacheSet(ways));
}

// Probe this level of the cache using the address
void CacheLevel::probe(uint64_t addr, CacheSet &set) {
  // Inc. the number of accesses
  stats.accesses++;

  // Inc the number of hits based on the results
  auto hit = set.probe(addr);
  stats.hits += hit;
}
