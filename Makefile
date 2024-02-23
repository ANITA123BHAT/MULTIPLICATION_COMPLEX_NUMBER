CC = g++
CFLAGS = -Wall
SRC_DIR = src
INCLUDE_DIR = include

main: main.o $(SRC_DIR)/display.o
	$(CC) $(CFLAGS) main.o  $(SRC_DIR)/display.o -o main

main.o: main.cpp $(INCLUDE_DIR)/complex.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o 

$(SRC_DIR)/display.o: $(SRC_DIR)/display.cpp $(INCLUDE_DIR)/complex.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/display.cpp -o $(SRC_DIR)/display.o 

clean:
	rm -f $(SRC_DIR)/*.o main