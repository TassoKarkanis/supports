CC = g++ -g
CFLAGS = -g -I. -c -std=c++14
LINK = g++
OBJECTS = main.o tests.o TestData.o \
          Raceway.o Segment.o Endpoint.o Vector.o \
          compute_supports.o

supports: $(OBJECTS)
	$(LINK) -o supports $(OBJECTS)

run_supports: supports
	./supports

clean:
	rm *.o
	rm supports

%.o : %.cpp *.h
	$(CC) $(CFLAGS) $< -o $@
