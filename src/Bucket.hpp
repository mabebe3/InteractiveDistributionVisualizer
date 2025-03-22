#ifdef BUCKET_HPP
#define BUCKET_HPP

#include <vector>
#include "Pop.hpp"

struct Bucket {
	float minValue;
	float maxValue;
	std::vector<Pop> pops;
};

#endif