CC=g++

all: task1 task4

task1: src/task1.cpp
	$(CC) $(CFLAGS) $(CLIBS) src/task1.cpp -o bin/task1

task4: src/task4.cpp
	$(CC) $(CFLAGS) $(CLIBS) src/task4.cpp -o bin/task4

clean:
	rm -f !(bin/.gikeep)
