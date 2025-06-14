CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
# Your .hpp files
DEPS = FibLFSR.hpp
# Your compiled .o files
OBJECTS = FibLFSR.o 
# The name of your program
PROGRAM = PhotoMagic

STATIC_LIB = PhotoMagic.a

.PHONY: all clean lint

all: $(PROGRAM) test $(STATIC_LIB)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(PROGRAM): main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

test: test.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(STATIC_LIB): $(OBJECTS)
	ar rcs $@ $(OBJECTS)

clean:
	rm *.o $(PROGRAM) test $(STATIC_LIB)

lint:
	cpplint *.cpp *.hpp
