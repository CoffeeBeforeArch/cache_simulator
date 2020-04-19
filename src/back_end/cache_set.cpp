// This file contains the implementation of the cache set methods
// By: Nick from CoffeeBeforeArch
// 4/16/2020

#include "cache_set.hh"
#include <algorithm>
#include <functional>
#include <numeric>
#include "../pb/cacheConfig.pb.h"

// Constructor
// Resizes each set based on the number of ways
CacheSet::CacheSet(int ways) {
  lines.resize(ways);
  priority.resize(ways);
  set_mask.resize(ways);
}

// Probe
// Looks up an address in the cache set and returns true if found
bool CacheSet::probe(uint64_t addr) {
  // Look up the address in the set
  auto result = std::find(begin(lines), end(lines), addr);
  auto hit = result != end(lines);

  // Replace line if not found
  if (!hit) replace_line(addr);

  // Return the probe status
  return hit;
}

// Replace Line
// Replace a line in the cache
void CacheSet::replace_line(uint64_t addr) {
  // Check for empty slots
  auto empty_slots =
      std::reduce(begin(set_mask), end(set_mask), 0, std::bit_or<bool>());

  // Put the address in the first empty slot
  if (empty_slots) {
    // Find the first 0
    auto it = std::find(begin(set_mask), end(set_mask), false);
    auto index  = std::distance(begin(set_mask), it);
    
    // Place the address and return
    lines[index] = addr;
    return;
  }

  // Find the lowest priority element
  auto it = std::min_element(begin(lines), end(lines));
  
  // Replace the address, and reset the priority
  auto index  = std::distance(begin(lines), it);
  lines[index] = addr;
  priority[index] = 0;
}
