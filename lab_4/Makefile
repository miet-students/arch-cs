CC=g++

all: task1 task2 task3

task1: src/task1.cpp src/task1.cpp
	$(CC) src/task1.cpp src/task1.S -o bin/task1

task2: src/task2.S
	$(CC) -lc src/task2.S -o bin/task2

task3: src/task3.cpp src/task3.cpp
	$(CC) src/task3.cpp src/task3.S -o bin/task3

clean:
	rm -f !(bin/.gikeep)
