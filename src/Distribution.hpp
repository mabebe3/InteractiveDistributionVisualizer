#ifdef DISTRIBUTION_HPP
#define DISTRIBUTION_HPP

#include "Pop.hpp"
#include "Bucket.hpp"
#include <vector>

class Distribution {
public:

	Distribution();

	void addPopToBucket(int bucketIndex, Pop pop);
	void movePopBetweenBuckets(int sourceBucket, int targetBucket, Pop pop);
	void adjustDistribution(int bucketIndex, int deltaPopulation);
	// comp frequencies
private:
	std::vector<Bucket> buckets;
	int totalPopulation;

};

#endif