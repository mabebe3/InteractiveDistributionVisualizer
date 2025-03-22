#ifdef BUCKET_HPP
#define BUCKET_HPP

#include <vector>
#include "Pop.hpp"

struct Bucket {
	int minValue;
	int maxValue;
	std::vector<Pop> pops;
};

class Bucket {
public:
	Bucket();

	void generateBuckets();
};
#endif