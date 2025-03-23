#include <vector>
#include "Pop.hpp"
#include "Bucket.hpp"

Bucket::Bucket(int min, int max, std::vector<Pop> pops) {
	minValue = min;
	maxValue = max;
	this->pops = pops;
}

void addPop() {

}
bool removePop() {

}

int getMin();
int getMax();
void setFrequency();
int getPopCount();
std::vector<Pop>& getPops();