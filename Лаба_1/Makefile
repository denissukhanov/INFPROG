CC=g++
EXEC_NAME=lab1
all: clean build run
clean:
	rm -rf $(EXEC_NAME).exe DecString.o SymbString.o main.o
build:
	$(CC) -c DecString.cpp --std=c++17
	$(CC) -c SymbString.cpp --std=c++17
	$(CC) -c main.cpp --std=c++17
	$(CC) *.o -o $(EXEC_NAME)
run:
	./$(EXEC_NAME)