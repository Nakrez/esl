CC = clang++
CFLAGS = -Wall -Wextra -g -std=c++11 -fPIC

OBJ = io.o

all: libio

libio: $(OBJ)
	$(CC) -shared $(OBJ) -ldl -o ../io.eslm

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
