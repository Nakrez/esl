CC = g++
CFLAGS = -g -Wall -Wextra -std=c++0x -fPIC

OBJ = sys.o

all: libsys

libsys: $(OBJ)
	$(CC) -shared $(OBJ) -o ../../sys.eslm

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f ../../sys.eslm
