CC = g++

SRC = ./src
MATRIX_MODULE_SRC = $(SRC)/matrix/src
MATRIX_MODULE_INCLUDE = $(SRC)/matrix/include

INC = -std=c++17 -I$(MATRIX_MODULE_INCLUDE)


all: main

main: $(SRC)/main.cpp complex.o # matrix.o
	$(CC) $(INC) -o main $(SRC)/main.cpp complex.o # matrix.o

matrix.o: $(MATRIX_MODULE_SRC)/matrix.cpp $(MATRIX_MODULE_INCLUDE)/matrix.h
	$(CC) $(INC) -o matrix.o -c $(MATRIX_MODULE_SRC)/matrix.cpp

complex.o: $(MATRIX_MODULE_SRC)/complex.cpp $(MATRIX_MODULE_INCLUDE)/complex.h
	$(CC) $(INC) -o complex.o -c $(MATRIX_MODULE_SRC)/complex.cpp


#test:

clean:
	rm -f main *.o
