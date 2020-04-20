// This file contains the implementation of the cache set methods
// By: Nick from CoffeeBeforeArch
// 4/16/2020

#include "cache_set.hh"
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include "../pb/cacheConfig.pb.h"

// Constructor
// Resizes each set based on the number of ways
CacheSet::CacheSet(int ways) {
  lines.resize(ways);
  priority.resize(ways);
  //std::fill_n(std::back_inserter(priority), ways,
  //            std::numeric_limits<unsigned>::max());
}

// Probe
// Looks up an address in the cache set and returns true if found
bool CacheSet::probe(uint64_t addr) {
  // Look up the address in the set
  auto result = std::find(begin(lines), end(lines), addr);
  auto hit = result != end(lines);

  // Find the latest line updated
  int latest_line;

  // Replace line if not found
  if (!hit)
    latest_line = replace_line(addr);
  else
    latest_line = std::distance(begin(lines), result);

  // Update the priority
  update_priority(latest_line);

  // Return the probe status
  return hit;
}

// Replace Line
// Replace a line in the cache
int CacheSet::replace_line(uint64_t addr) {
  // Check for empty slots
  auto full = used_lines != lines.size();

  // Put the address in the first empty slot
  if (!full) {
    // Place the address, update the used lines, and return
    lines[used_lines] = addr;
    return used_lines++;
  }

  // Find the lowest priority element (the max number)
  auto it = std::max_element(begin(priority), end(priority));

  // Replace the address, and reset the priority
  auto index = std::distance(begin(priority), it);
  lines[index] = addr;
  return index;
}

// Update the priority
// Set the priority of the latest line to 0
void CacheSet::update_priority(int latest_line) {
  // Update everyone and zero out the other prio
  // Removes a branch
  for(auto &p : priority) p++;
  priority[latest_line] = 0;
}
