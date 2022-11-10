OPTIONS = -Wall
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp Rectangle.cpp Square.cpp Circle.cpp Trapezoid.cpp
	$(CXX) $(OPTIONS) main.cpp Rectangle.cpp Square.cpp Circle.cpp Trapezoid.cpp -o $(PROGRAM) -std=c++11

clean:
	rm -f $(PROGRAM)

