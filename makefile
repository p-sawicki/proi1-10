CC=g++
CFLAGS=-I -Wall 
DEPS1 = vector.h
DEPS2 = vector-main.h
DEPS3 = vector-test.h
OBJ = vector.o vector-main.o vector-test.o

%.o: %.cpp $(DEPS1)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(DEPS2)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(DEPS3)
	$(CC) -c -o $@ $< $(CFLAGS)

vector: $(OBJ)
	$(CC) -o $@ $^ 

.PHONY: clean

clean:
	rm -f *.o *~ core
