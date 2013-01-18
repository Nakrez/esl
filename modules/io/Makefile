CC = g++
CFLAGS = -g -Wall -Wextra -std=c++0x -fPIC

OBJ = io.o file.o file-object.o

all: libio

libio: $(OBJ)
	$(CC) -shared $(OBJ) -o ../../io.eslm

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f ../../io.eslm
