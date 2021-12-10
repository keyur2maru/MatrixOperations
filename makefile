matrix: main.o matrix.o
	rm main.o
	rm matrix.o
	g++ -c main.cpp matrix.cpp
	g++ -o matrix main.o matrix.o
clean:
	rm *.o matrix

