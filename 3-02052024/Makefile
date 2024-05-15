all: 
	make punto
	make quadrilatero
	make quadrato
	make main

punto:
	g++ -c punto.cpp -o punto.o

quadrilatero:
	g++ -c quadrilatero.cpp -o quadrilatero.o

quadrato:
	g++ -c quadrato.cpp -o quadrato.o

main:
	g++ -o main.o punto.o quadrilatero.o quadrato.o main.cpp

clean:
	rm punto.o quadrilatero.o quadrato.o main.o