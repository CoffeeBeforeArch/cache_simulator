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
  // Vector of cache line starting addresses
  std::vector<CacheSet> sets;

  // Associativity of the cache
  const uint64_t num_sets;

  // Line size of the cache
  const uint32_t line_size;
  
  // Miss penalty of the cache
  const uint32_t miss_penalty;

  // Dirty writeback penalty of the cache
  const uint32_t dirty_wb_penalty;
  
  // Number of store hits
  uint64_t store_hits = 0;
  
  // Number of load hits
  uint64_t load_hits = 0;

  // Number of store accesses
  uint64_t store_accesses = 0;

  // Number of load accesses
  uint64_t load_accesses = 0;

  // Number of dirty evictions
  uint64_t dirty_evictions = 0;

  // Number of instructions
  uint64_t instructions = 0;
};

#endif
