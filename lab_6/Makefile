CC=g++

all: task1 task2 task3 task4 task5

task1: src/task1.cpp src/task1.S
	$(CC) src/task1.cpp src/task1.S -o bin/task1

task2: src/task2.cpp src/task2.S
	$(CC) src/task2.cpp src/task2.S -o bin/task2

task3: src/task3.cpp
	$(CC) src/task3.cpp -o bin/task3

task4: src/task4.cpp
	$(CC) src/task4.cpp -o bin/task4

task5: src/task5.cpp
	$(CC) src/task5.cpp -o bin/task5

clean:
	rm -f !(bin/.gikeep)
