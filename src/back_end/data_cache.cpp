// This file contains the implementation of the data cache methods
// By: Nick from CoffeeBeforeArch
// 4/15/2020

#include "data_cache.hh"
#include <algorithm>
#include <bit>
#include <cstdint>
#include "../pb/cacheConfig.pb.h"
#include <iostream>
// Constructor
CacheLevel::CacheLevel(CacheConfig config)
    : num_sets(config.cache_size() / config.line_size() /
               config.associativity()),
      line_size(config.line_size()) {
  // Allocate and initialize the cache
  std::fill_n(std::back_inserter(sets), num_sets,
              CacheSet(config.associativity()));
}

// Probe this level of the cache using the address
void CacheLevel::probe(uint64_t addr, bool type) {
  // Shift over to access the set bits
  auto shifted_number = addr >> (std::popcount(line_size - 1));

  // Extract the set bits
  auto set_number = shifted_number & (num_sets - 1);
  
  // Get the tag bits
  auto tag = shifted_number >> (std::popcount(num_sets - 1));
  
  // Get the cache set
  auto &set = sets[set_number];

  // Inc the number of hits based on the results
  auto hit = set.probe(tag);

  // Update stats based on type
  if (type) {
    stats.store_accesses++;
    stats.store_hits += hit;
  } else {
    stats.load_accesses++;
    stats.load_hits += hit;
  }
}

// Destructor
// Dumps the stats to the screen
CacheLevel::~CacheLevel() { stats.dump_stats(); }
