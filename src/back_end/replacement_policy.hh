// This file contains the class definitions for the replacement policy
// By: Nick from CoffeeBeforeArch
// 4/19/2020

#include <cstdint>
#include <string>
#include <vector>

// Top-level cache replacement policy class
class ReplacementPolicy {
 public:
  // Constructors/Destructors
  ReplacementPolicy(int ways);
  ~ReplacementPolicy() = default;

  // Replacement policy functionality methods
  unsigned update_priority();

 private:
  // Data members
  // Vector of cache line priorities
  // (Higher is better)
  std::vector<unsigned> priority;

  // Mask of unused cache lines in the set
  // Optimization while sets are still empty
  std::vector<bool> mask;
};
