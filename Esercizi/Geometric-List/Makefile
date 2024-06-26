CXX=g++
CXXFLAGS=-std=c++2a

all: CreateFolder bin/Geometric-List

CreateFolder:
	mkdir -p bin obj

bin/Geometric-List: obj/Geometric-List.o
	$(CXX) $< -o $@

obj/Geometric-List.o: src/Geometric-List.cpp
	$(CXX) -c $< -o $@

clean:
	rm -f bin/* obj/*
	rmdir bin obj
