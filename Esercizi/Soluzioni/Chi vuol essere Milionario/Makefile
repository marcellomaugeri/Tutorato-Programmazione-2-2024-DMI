CXX = g++
#CXXFLAGS = -std=c++2a
OBJECTS = bin/Chi\ vuol\ essere\ Milionario.o

all: create_folder copy_file bin/Chi\ vuol\ essere\ Milionario

create_folder:
	mkdir -p bin

copy_file:
	cp domande.txt /tmp

bin/Chi\ vuol\ essere\ Milionario.o: src/Chi\ vuol\ essere\ Milionario.cpp
	$(CXX) $(CXXFLAGS) -c src/Chi\ vuol\ essere\ Milionario.cpp -o bin/Chi\ vuol\ essere\ Milionario.o

bin/Chi\ vuol\ essere\ Milionario: bin/Chi\ vuol\ essere\ Milionario.o
	$(CXX) bin/Chi\ vuol\ essere\ Milionario.o -o bin/Chi\ vuol\ essere\ Milionario
	rm -f bin/Chi\ vuol\ essere\ Milionario.o

clean:
	rm -f bin/*
	rm -f /tmp/domande.txt
	rm -f /tmp/esatte.txt
	rmdir bin