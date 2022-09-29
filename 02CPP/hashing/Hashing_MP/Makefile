CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -g -fstandalone-debug -Wall -Wextra -Werror -pedantic $(INCLUDES)

exec: bin/exec
tests: bin/tests

bin/exec: ./src/main.cpp ./src/hash_table.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

bin/tests: ./tests/tests.cc obj/catch.o ./src/hash_table.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

obj/catch.o: tests/catch.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -fr bin/* 
