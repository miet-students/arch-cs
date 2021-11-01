CC=g++

all: task1 task2

task1: src/task1.cpp src/task1.S
	$(CC) src/task1.cpp src/task1.S -o bin/task1

task2: src/task2.cpp src/task2.S
	$(CC) src/task2.cpp src/task2.S -o bin/task2

clean:
	rm -f !(bin/.gikeep)
