// This file contains the implementation of the cache set methods
// By: Nick from CoffeeBeforeArch
// 4/16/2020

#include "access.hh"

#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
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
// Returns a single memory access, the number of in-between instructions, and
// the type
std::tuple<uint64_t, unsigned, bool> CacheAccess::get_access() {
  // Make the tuple
  auto ret_val =
      std::make_tuple(addresses[current_access], instructions[current_access],
                      types[current_access]);

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
      std::string addr_string;
      bool type;
      int insns;

      // Get the values
      ss >> sink;
      ss >> type;
      ss >> addr_string;
      ss >> insns;

      // Convert address string to hex value
      uint64_t addr = std::stoull(addr_string, nullptr, 16);

      // Fill in the values
      addresses[i] = addr;
      instructions[i] = insns;
      types[i] = type;
    } else {
      // End the loop early (file ended)
      break;
    }
  }

  // Save the file position and return the number of instructions read
  file_position = file.tellg();
  return i;
}
