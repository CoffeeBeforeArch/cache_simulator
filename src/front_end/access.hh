// This file contains the class definitions for cache accesses
// By: Nick from CoffeeBeforeArch
// 4/17/2020

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
  std::tuple<uint64_t, bool> get_access();
  // Fetch a new batch of accesses and return how many were found
  unsigned fetch_access_batch();
  // Parse data from input file
  unsigned parse_input_file();

 private:
  // Data members
  // Addresses
  std::vector<uint64_t> addresses;

  // Instructions between accesses (for cycle count later)
  std::vector<unsigned> instructions;

  // Load/store (support prefetch later?)
  std::vector<bool> types;

  // File name for memory accesses
  const std::string f_name;

  // Current memory access
  unsigned current_access = 0;

  // Current file position;
  unsigned file_position = 0;
};
