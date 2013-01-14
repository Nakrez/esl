CC = g++
CFLAGS = -Wall -Wextra -std=c++0x -fPIC

OBJ = array-module.o array.o array-object.o

all: libarray

libarray: $(OBJ)
	$(CC) -shared $(OBJ) -o ../../array.eslm

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f ../../array.eslm
