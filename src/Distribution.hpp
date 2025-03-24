#ifndef DISTRIBUTION_HPP
#define DISTRIBUTION_HPP

#include "Pop.hpp"
#include "Bucket.hpp"
#include <vector>
#include <string>



class Distribution {
public:
	struct dist {
		std::vector<Bucket> buckets;
		int totalPopulation;
		int numBuckets;
		int min;
		int max;
	};
	Distribution(std::vector<Bucket> buckets, int popSize, int numBuckets, int min, int max);
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

	/*void addPopToBucket(int bucketIndex, Pop pop);
	void moveAPopBetweenBuckets(int sourceBucket, int targetBucket, Pop pop);*/
	//void adjustDistribution(int bucketIndex, int deltaPopulation);
	
	// generateDistribution(str::string distName, str::string bucketName);
	//void generateDistribution(std::string distName);
	void generateBuckets(std::string bucketName);
	void uniformDistribution(int popSize, int numBuckets);
	int getNumBuckets() const;
	int getPopSize() const;

	float getStd() const;
	float getMean() const;

private:
	dist Dist;
	std::string disttype;

};

#endif