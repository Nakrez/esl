CC = g++
CFLAGS = -Wall -Wextra -std=c++0x -fPIC

OBJ = stack-module.o stack.o stack-object.o

all: libstack

libstack: $(OBJ)
	$(CC) -shared $(OBJ) -o ../../stack.eslm

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f ../../stack.eslm
