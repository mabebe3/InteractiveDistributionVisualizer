#ifdef DISTRIBUTION_HPP
#define DISTRIBUTION_HPP

#include "Pop.hpp"
#include "Bucket.hpp"
#include <vector>



class Distribution {
public:
	struct dist {
		std::vector<Bucket> buckets;
		int totalPopulation;
		int min;
		int max;
	};
	Distribution(std::vector<Bucket> buckets, int popSize, int min, int max);
	/*getDistStats();*/

	/*setMin()
	getMin()
	setMax()
	getMax()*/

	/*void getBucket(int bucketIndex);
	void setBucket(int bucketIndex);
	void removeBucket(int bucketIndex);*/

	/*getpopulation();
	setpopulation(int size);
	deltaPopulation(int change)*/

	void addPopToBucket(int bucketIndex, Pop pop);
	void moveAPopBetweenBuckets(int sourceBucket, int targetBucket, Pop pop);
	//void adjustDistribution(int bucketIndex, int deltaPopulation);
	
	// generateDistribution(str::string distName, str::string bucketName);

private:
	dist Dist;

};

#endif