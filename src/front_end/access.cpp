// This file contains the implementation of the cache set methods
// By: Nick from CoffeeBeforeArch
// 4/16/2020

#include "access.hh"
#include <cstdint>
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>

// Constructor
// Resizes based on the batch size of addresses to process
// (Will be neat to experiment how to best load data from a file)
CacheAccess::CacheAccess(unsigned batch_size, std::string trace_file)
    : f_name(trace_file) {
  // Resize all the vectors
  addresses.resize(batch_size);
  instructions.resize(batch_size);
  types.resize(batch_size);
}

// Get access
// Returns a single memory access and the access type in a tuple
std::tuple<uint64_t, bool> CacheAccess::get_access() {
  // Make the tuple
  auto ret_val =
      std::make_tuple(addresses[current_access], types[current_access]);
  
  // Increment the current access
  current_access++;

  return ret_val;
}

// Fetch access batch
// Re-loads the internal vectors with new accesses from a trace
// Returns the number of accesses parsed
unsigned CacheAccess::fetch_access_batch() {
  // Reset the access number we're on
  current_access = 0;

  // Get new accesses from the trace file and return the number of them
  return parse_input_file();
}

// Parse input file
// Gets accesses and their types from an input files
unsigned CacheAccess::parse_input_file() {
  // Open the file and seek to the last position
  std::ifstream file(f_name);
  file.seekg(file_position);

  // Read in one batch (at most)
  size_t i;
  for (i = 0; i < addresses.size(); i++) {
    std::string line;
    if (std::getline(file, line)) {
      // Use stringstream to parse the line
      std::stringstream ss(line);

      // Fields to parse from the string
      std::string sink;
      uint64_t addr;
      bool type;
      int insns;

      // Get the values
      ss >> sink;
      ss >> addr;
      ss >> type;
      ss >> insns;

      // Fill in the values
      addresses[i] = addr;
      instructions[i] = insns;
      types[i] = type;
    }
  }

  // Save the file position and return the number of instructions read
  file_position = file.tellg();
  return i;
}
