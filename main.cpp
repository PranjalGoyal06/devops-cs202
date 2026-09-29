#include <cassert>
#include <iostream>

#include "mathfuncs.h"

void runMathTests() {
	assert(add(2, 3) == 5);
	assert(subtract(7, 4) == 3);
	assert(multiply(6, 5) == 30);
	assert(divide(20, 4) == 5);
}

int main() {
	double firstNumber;
	double secondNumber;
	char operation;

	runMathTests();

	std::cout << "Enter an expression (for example, 2 + 3): ";
	if (!(std::cin >> firstNumber >> operation >> secondNumber)) {
		std::cout << "Invalid expression.\n";
		return 1;
	}

	switch (operation) {
		case '+':
			std::cout << add(firstNumber, secondNumber) << '\n';
			break;
		case '-':
			std::cout << subtract(firstNumber, secondNumber) << '\n';
			break;
		case '*':
			std::cout << multiply(firstNumber, secondNumber) << '\n';
			break;
		case '/':
			if (secondNumber == 0) {
				std::cout << "Cannot divide by zero.\n";
				return 1;
			}
			std::cout << divide(firstNumber, secondNumber) << '\n';
			break;
		default:
			std::cout << "Unsupported operation.\n";
			return 1;
	}

	return 0;
}
