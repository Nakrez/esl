CC = clang++
CFLAGS = -Wall -Wextra -g -Isrc -std=c++11 -fPIC

OBJ = callback.o class-def.o content-object.o context.o function.o function.o \
	module.o object-instance.o runtime.o value.o

all: libesl

libesl: $(OBJ)
	$(CC) -shared $(OBJ) -o ../libesl.so

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
