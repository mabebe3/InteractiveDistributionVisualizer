#include <iostream>
#include <random>

int generateRandBound(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(this->min = min, this->max = max)
	int randomNum = dist(gen);
	return randomNum;
}