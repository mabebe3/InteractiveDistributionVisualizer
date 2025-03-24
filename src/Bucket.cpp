#include <vector>
#include "Pop.hpp"
#include "Bucket.hpp"

Bucket::Bucket(int min, int max, std::vector<Pop> pops) {
	minValue = min;
	maxValue = max;
	this->pops = pops;
	frequency = 0;
}

void Bucket::addPop(const Pop& pop) {
	pops.push_back(pop);
}
bool Bucket::removePop() {
	if (!pops.empty()) {
		pops.pop_back();
		return true;
	}
	return false;
}

int Bucket::getMin() const {
	return minValue;
}

int Bucket::getMax() const {
	return maxValue;
}

void Bucket::setFrequency(int freq) {
	frequency = freq;
}
int Bucket::getPopCount() const {
	return static_cast<int>(pops.size());
}

std::vector<Pop>& Bucket::getPops() {
	return pops;
}

float Bucket::getBucketSum() const {
	float sum = 0;
	for (auto& pop : pops) {
		sum += pop.income;

	}
	return sum;
}

float Bucket::stdHelper(float popMean) const {
	float deviation = 0;
	for (auto& pop : pops) {
		deviation += std::pow((pop.income - popMean),2);

	}
	return deviation;
}
	