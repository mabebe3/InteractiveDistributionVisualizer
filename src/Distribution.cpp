#include "Pop.hpp"
#include "Bucket.hpp"
#include "Distribution.hpp"

Distribution::Distribution() {

}

void Distribution::addPopToBucket(int bucketIndex, Pop pop);
void Distribution::movePopBetweenBuckets(int sourceBucket, int targetBucket, Pop pop);
void Distribution::adjustDistribution(int bucketIndex, int deltaPopulation);