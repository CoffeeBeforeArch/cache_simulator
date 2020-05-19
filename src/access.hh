// This file contains the class definitions for cache accesses
// By: Nick from CoffeeBeforeArch
// 4/17/2020

#ifndef CACHE_ACCESS
#define CACHE_ACCESS

#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

// Top-level cache access class
class CacheAccess {
 public:
  // Constructors/Destructors
  CacheAccess(unsigned batch_size, std::string trace_file);
  ~CacheAccess() = default;

  // Cache access functionality methods
  // Return a tuple of access and access type
  std::tuple<uint64_t, uint32_t, uint8_t> get_access();
  // Fetch a new batch of accesses and return how many were found
  unsigned fetch_access_batch();
  // Parse data from input file
  unsigned parse_input_file();

 private:
  // Data members
  // Addresses
  std::vector<uint64_t> addresses;

  // Instructions between accesses (for cycle count later)
  std::vector<uint32_t> instructions;

  // Load/store (support prefetch later?)
  std::vector<uint8_t> types;

  // File name for memory accesses
  const std::string f_name;

  // Current memory access
  uint32_t current_access = 0;

  // Current file position;
  uint32_t file_position = 0;

  // count the number of accesses
  uint64_t access = 0;
};

#endif
