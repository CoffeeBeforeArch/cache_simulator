# A simple makefile for the simulator

CXX_FLAGS = -O3 -march=native -mtune=native -flto -fuse-linker-plugin --std=c++2a
LINKER_FLAGS = -lprotobuf

driver : access.o cache_config.pb.o cache_set.o data_cache.o simulation.o driver.o
	g++ access.o cache_config.pb.o cache_set.o data_cache.o simulation.o driver.o \
		${CXX_FLAGS} ${LINKER_FLAGS} -o driver

driver.o : driver.cpp
	g++ -c driver.cpp ${CXX_FLAGS}

simulation.o : simulation.cpp
	g++ -c simulation.cpp ${CXX_FLAGS}

data_cache.o : data_cache.cpp
	g++ -c data_cache.cpp ${CXX_FLAGS}

cache_set.o : cache_set.cpp
	g++ -c cache_set.cpp ${CXX_FLAGS}

access.o : access.cpp
	g++ -c access.cpp ${CXX_FLAGS}

cache_config.pb.o : cache_config.pb.cc
	g++ -c cache_config.pb.cc ${CXX_FLAGS}

cache_config.pb.cc : cache_config.proto
	protoc --cpp_out=./ cache_config.proto

clean :
	rm -rf driver
	rm -rf *.o
	rm -rf *.pb.*

