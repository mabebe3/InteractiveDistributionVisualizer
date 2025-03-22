#include <vector>
#include "Pop.hpp"
#include "Bucket.hpp"

Bucket::Bucket(int min, int max) {
	minValue = min;
	maxValue = max;
}

void addPop() {

}
bool removePop();

int getMin();
int getMax();
void setFrequency();
int getPopCount();
std::vector<Pop>& getPops();