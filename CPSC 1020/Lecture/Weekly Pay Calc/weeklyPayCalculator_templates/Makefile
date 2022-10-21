default: weeklyPayCalculator.out

weeklyPayCalculator.out: weeklyPayCalculator.cpp calcWeeklyPay.cpp getChoice.cpp
	g++ -Wall -o weeklyPayCalculator.out weeklyPayCalculator.cpp calcWeeklyPay.cpp getChoice.cpp

run: weeklyPayCalculator.out
	./weeklyPayCalculator.out

clean:
	rm weeklyPayCalculator.out 

