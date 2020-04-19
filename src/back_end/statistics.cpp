// This file contains the struct implementations for statistics
// By: Nick from CoffeeBeforeArch
// 4/15/2020

#include "statistics.hh"
#include <iostream>

// Constructor
// Zeros out the statistics
CacheStats::CacheStats() : accesses(0), hits(0), stores(0), instructions(0) {}

// Dump stats
// Dump the collected stats to the screen
void CacheStats::dump_stats() const {
  std::cout << "ACCESSES:\t" << accesses << '\n';
  std::cout << "STORES:\t\t" << stores << '\n';
  std::cout << "LOADS:\t\t" << accesses - stores << '\n';
  std::cout << "HITS:\t\t" << hits << '\n';
  std::cout << "HIT RATE:\t" << (double) hits / (double) accesses << '\n';
}
