CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -g -fstandalone-debug -Wall -Wextra -Werror -pedantic $(INCLUDES)

exec: bin/exec
tests: bin/tests

bin/exec: src/main.cpp src/stringlinkedlist.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

bin/tests: obj/catch.o tests/tests.cpp src/stringlinkedlist.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: clean

clean:
	rm -f bin/*

