#include "randfuncs.h"

#include <random>

namespace {
std::mt19937& randomEngine() {
	static std::mt19937 engine(std::random_device{}());
	return engine;
}
}

bool flipCoin() {
	std::bernoulli_distribution coin(0.5);
	return coin(randomEngine());
}

int rollSixSidedDie() {
	std::uniform_int_distribution<int> die(1, 6);
	return die(randomEngine());
}

int rollTenSidedDie() {
	std::uniform_int_distribution<int> die(1, 10);
	return die(randomEngine());
}