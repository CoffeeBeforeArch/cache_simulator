// This file contains the implementation of the data cache methods
// By: Nick from CoffeeBeforeArch
// 4/15/2020

#include "data_cache.hh"
#include <algorithm>
#include <bit>
#include <cstdint>
#include <iostream>
#include "cache_config.pb.h"

// Constructor
CacheLevel::CacheLevel(CacheConfig config)
    : num_sets(config.cache_size() / config.line_size() /
               config.associativity()),
      line_size(config.line_size()),
      miss_penalty(config.miss_penalty()),
      dirty_wb_penalty(config.dirty_wb_penalty) {
  // Allocate and initialize the cache
  std::fill_n(std::back_inserter(sets), num_sets,
              CacheSet(config.associativity()));
}

// Probe this level of the cache using the address
uint32_t CacheLevel::probe(uint64_t addr, bool type) {
  // Shift over to access the set bits
  // Use std::popcount to extract the number of bits to shift (c++2a)
  auto shifted_number = addr >> (std::popcount(line_size - 1));

  // Extract the set bits
  auto set_number = shifted_number & (num_sets - 1);

  // Get the tag bits
  // Use std::popcount to extract the number of bit to shift (c++2a)
  auto tag = shifted_number >> (std::popcount(num_sets - 1));

  // Get the cache set
  auto &set = sets[set_number];

  // Inc the number of hits based on the results
  auto [hit, dirty_wb] = set.probe(tag, type);

  // Update dirty evictions
  dirty_evictions += dirty_wb;

  // Update stats based on type
  if (type) {
    store_accesses++;
    store_hits += hit;
  } else {
    load_accesses++;
    load_hits += hit;
  }

  // Return the miss penalty only on a miss (same with drity writeback)
  // Avoid a branch by integrating the check into the mul
  // #TODO make penalty for dirty wb configurable
  return (miss_penalty * !hit) + (2 * dirty_wb);
}

// Destructor
// Dumps the stats to the screen
CacheLevel::~CacheLevel() {
  std::cout << "ACCESSES:\t" << store_accesses + load_accesses << '\n';
  std::cout << "STORES:\t\t" << store_accesses << '\n';
  std::cout << "STORE HITS:\t" << store_hits << '\n';
  std::cout << "STORE MISSES:\t" << store_accesses - store_hits << '\n';
  std::cout << "LOADS:\t\t" << load_accesses << '\n';
  std::cout << "LOAD HITS:\t" << load_hits << '\n';
  std::cout << "LOAD MISSES:\t" << load_accesses - load_hits << '\n';
  std::cout << "HIT RATE:\t"
            << (double)(store_hits + load_hits) /
                   (double)(store_accesses + load_accesses)
            << '\n';
}
