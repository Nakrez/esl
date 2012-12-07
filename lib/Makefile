CC = clang++
CFLAGS = -Wall -Wextra -g -std=c++11 -fPIC

OBJ = class-def.o content-object.o context.o module.o object-instance.o \
	runtime.o value.o executable-context.o params.o object.o \

all: libesl

libesl: $(OBJ)
	$(CC) -shared $(OBJ) -o ../libesl.so

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
