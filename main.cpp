#include <cassert>
#include <iostream>

#include "randfuncs.h"

void testFlipCoin() {
	bool sawHeads = false;
	bool sawTails = false;

	for (int attempt = 0; attempt < 1000; ++attempt) {
		if (flipCoin()) {
			sawHeads = true;
		} else {
			sawTails = true;
		}
	}

	assert(sawHeads && sawTails);
}

void testRollSixSidedDie() {
	for (int attempt = 0; attempt < 1000; ++attempt) {
		int result = rollSixSidedDie();
		assert(result >= 1 && result <= 6);
	}
}

void testRollTenSidedDie() {
	for (int attempt = 0; attempt < 1000; ++attempt) {
		int result = rollTenSidedDie();
		assert(result >= 1 && result <= 10);
	}
}

void runRandomFunctionTests() {
	testFlipCoin();
	testRollSixSidedDie();
	testRollTenSidedDie();
	std::cout << "Random function tests passed.\n";
}

int main() {
	double firstNumber;
	double secondNumber;
	char operation;

	runRandomFunctionTests();

	std::cout << "Enter an expression (for example, 2 + 3): ";
	if (!(std::cin >> firstNumber >> operation >> secondNumber)) {
		std::cout << "Invalid expression.\n";
		return 1;
	}

	switch (operation) {
		case '+':
			std::cout << firstNumber + secondNumber << '\n';
			break;
		case '-':
			std::cout << firstNumber - secondNumber << '\n';
			break;
		case '*':
			std::cout << firstNumber * secondNumber << '\n';
			break;
		case '/':
			if (secondNumber == 0) {
				std::cout << "Cannot divide by zero.\n";
				return 1;
			}
			std::cout << firstNumber / secondNumber << '\n';
			break;
		default:
			std::cout << "Unsupported operation.\n";
			return 1;
	}

	std::cout << "Coin flip: " << (flipCoin() ? "heads" : "tails") << '\n';
	std::cout << "Six-sided die: " << rollSixSidedDie() << '\n';
	std::cout << "Ten-sided die: " << rollTenSidedDie() << '\n';

	return 0;
}
