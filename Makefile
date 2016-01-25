# Christian Paffrath, 114980, WS2015-2016
all: main test

main:
	g++ --std=c++11 -Wall -o main main.cpp

test:
	./main

clean:
	rm main *.o

