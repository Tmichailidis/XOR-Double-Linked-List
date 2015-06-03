OBJ = main.o
SOURCE = main.cpp
HEADER = XORList.hpp XORSortedList.hpp
OUT = xorlist
CC = g++
FLAGS = -c -g

all: $(OBJ) $(HEADER)
	$(CC) -Wall -g $(OBJ) -o $(OUT)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

#clean
clean:
	rm -f $(OBJ) $(OUT)