CXX=g++
#CXXFLAGS=-std=c++2a

all: CreateFolders bin/Rifugio

CreateFolders:
	mkdir -p obj bin

bin/Rifugio: obj/Animale.o obj/Rifugio.o
	$(CXX) $(CXXFLAGS) $^ -o $@

obj/Animale.o: src/utils/Animale.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

obj/Rifugio.o: src/Rifugio.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf obj bin