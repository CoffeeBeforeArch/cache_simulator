// This file contains the implementation of the replacement policy methods
// By: Nick from CoffeeBeforeArch
// 4/19/2020

#include "replacement_policy.hh"
#include <algorithm>

ReplacementPolicy::ReplacementPolicy(int ways) {
  priority.resize(ways);
  mask.resize(ways);
}
