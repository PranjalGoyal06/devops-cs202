#include <iostream>

int main() {
	double firstNumber;
	double secondNumber;
	char operation;

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

	return 0;
}
