// This a simple driver for the simulator to test initial functionality
// By: Nick from CoffeeBeforeArch
// 4/17/2020

#include <string>
#include <tuple>
#include "../back_end/data_cache.hh"
#include "../front_end/access.hh"
#include "../pb/cacheConfig.pb.h"

int main(int argc, char *argv[]) {
  // Create a file
  std::string file_name(argv[1]);

  // Test our protobuf
  CacheConfig config;
  config.set_cache_size(1 << 16);
  config.set_line_size(1 << 6);
  config.set_associativity(1 << 3);

  // Create our cache based on our config
  CacheLevel CL(config);

  // Create our cache access object
  CacheAccess CA(1 << 12, file_name);

  // Get a new batch of accesses
  size_t accesses = CA.fetch_access_batch();

  // Continue until we run out of accesses
  while (accesses) {
    for (size_t i = 0; i < accesses; i++) {
      auto [addr, type] = CA.get_access();
      CL.probe(addr, type);
      accesses--;
    }

    // Try and fetch some more
    accesses = CA.fetch_access_batch();
  }
  return 0;
}
