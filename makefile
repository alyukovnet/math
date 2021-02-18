CC = g++

SRC = ./src
MATRIX_MODULE_SRC = $(SRC)/matrix/src
MATRIX_MODULE_INCLUDE = $(SRC)/matrix/include

INC = -std=c++17 -I$(MATRIX_MODULE_INCLUDE)


all: main

main: $(SRC)/main.cpp matrix.o
	$(CC) $(INC) -o main $(SRC)/main.cpp matrix.o

matrix.o: $(MATRIX_MODULE_SRC)/matrix.cpp $(MATRIX_MODULE_INCLUDE)/matrix.h
	$(CC) $(INC) -o matrix.o -c $(MATRIX_MODULE_SRC)/matrix.cpp


#test:

clean:
	rm -f main *.o
