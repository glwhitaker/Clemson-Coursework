COMPILER = g++
OPTIONS = -Wall
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp Date.cpp
	$(COMPILER) $(OPTIONS) main.cpp Date.cpp -o $(PROGRAM) -std=c++11

clean:
	rm -f $(PROGRAM)