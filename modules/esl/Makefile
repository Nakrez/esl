CC = g++
CFLAGS = -g -Wall -Wextra -std=c++0x -fPIC

OBJ = esl.o

all: libesl

libesl: $(OBJ)
	$(CC) -shared $(OBJ) -o ../../esl.eslm

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f ../../esl.eslm
