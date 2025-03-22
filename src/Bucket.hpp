#ifdef BUCKET_HPP
#define BUCKET_HPP

#include <vector>
#include "Pop.hpp"

//struct Bucket {
//	int minValue;
//	int maxValue;
//	int frequency;
//	std::vector<Pop> pops;
//};

class Bucket {
private:
	int minValue;
	int maxValue;
	int frequency;
	std::vector<Pop> pops;

public:
	Bucket(int min, int max);

	void addPop();
	bool removePop();

	int getMin();
	int getMax();
	void setFrequency();
	int getPopCount();
	std::vector<Pop>& getPops();
};

#endif