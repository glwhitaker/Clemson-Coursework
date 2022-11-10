COMPILER = g++
OPTIONS = -Wall
PROGRAM = hospitalCharges.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): hospitalCharges.cpp calcTotalCharges.cpp validateUserInput.cpp
	$(COMPILER) $(OPTIONS) hospitalCharges.cpp calcTotalCharges.cpp validateUserInput.cpp -o $(PROGRAM)

clean:
	rm -f $(PROGRAM)