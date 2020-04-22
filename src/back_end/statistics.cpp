// This file contains the struct implementations for statistics
// By: Nick from CoffeeBeforeArch
// 4/15/2020

#include "statistics.hh"
#include <iostream>

// Constructor
// Zeros out the statistics
CacheStats::CacheStats()
    : store_hits(0),
      load_hits(0),
      store_accesses(0),
      load_accesses(0),
      instructions(0),
      dirty_evictions(0) {}

// Dump stats
// Dump the collected stats to the screen
void CacheStats::dump_stats() const {
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
