COMPILER = g++
OPTIONS = -Wall
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp employee.cpp visitor.cpp vendor.cpp student.cpp car.cpp lowEmission.cpp motorcycle.cpp moped.cpp Invoice.cpp
	$(COMPILER) $(OPTIONS) main.cpp employee.cpp visitor.cpp vendor.cpp student.cpp car.cpp lowEmission.cpp motorcycle.cpp moped.cpp Invoice.cpp -o $(PROGRAM)

clean:
	rm -f $(PROGRAM)