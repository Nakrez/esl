CC = clang++
CFLAGS = -Wall -Wextra -g -std=c++11 -fPIC

OBJ = class-def.o content-object.o context.o extension.o object-instance.o \
	runtime.o value.o executable-context.o params.o object.o module.o \

all: libesl

libesl: $(OBJ)
	$(CC) -shared $(OBJ) -ldl -o ../libesl.so

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
