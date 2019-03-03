CC=g++
CFLAGS=-I -g
DEPS1 = vector.h
DEPS2 = vector-main.h
DEPS3 = vector-test.h
OBJ = vector.o vector-main.o vector-test.o

%.o: %.c $(DEPS1)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.c $(DEPS2)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.c $(DEPS3)
	$(CC) -c -o $@ $< $(CFLAGS)

vector: $(OBJ)
	$(CC) -o $@ $^ 

.PHONY: clean

clean:
	rm -f *.o *~ core
