CC = g++

SRC = ./src
MATRIX_MODULE = $(SRC)/matrix

INC = -std=c++17 -I$(MATRIX_MODULE)/include -I./thirdparty

# Targets
all: main

main: $(SRC)/main.cpp complex.o # matrix.o
	$(CC) $(INC) -o main $(SRC)/main.cpp complex.o # matrix.o

complex.o: $(MATRIX_MODULE)/src/complex.cpp $(MATRIX_MODULE)/include/complex.h
	$(CC) $(INC) -o complex.o -c $(MATRIX_MODULE)/src/complex.cpp

matrix.o: $(MATRIX_MODULE)/src/matrix.cpp $(MATRIX_MODULE)/include/matrix.h
	$(CC) $(INC) -o matrix.o -c $(MATRIX_MODULE)/include/matrix.cpp

# Tests
test: test_complex.o # test_matrix.o
	./test_complex.o # && ./test_matrix.o

test_complex.o: $(MATRIX_MODULE)/test/test_complex.cpp complex.o
	$(CC) $(INC) -o test_complex.o $(MATRIX_MODULE)/test/test_complex.cpp complex.o

test_matrix.o: $(MATRIX_MODULE)/test/test_matrix.cpp matrix.o
	$(CC) $(INC) -o test_matrix.o $(MATRIX_MODULE)/test/test_matrix.cpp matrix.o

# Service
clean:
	rm -f main *.o
