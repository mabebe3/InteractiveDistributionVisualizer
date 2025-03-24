#include "Pop.hpp"
#include "Bucket.hpp"
#include "Distribution.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

Distribution::Distribution( std::vector<Bucket> buckets , int popSize, int numBuckets, int min, int max) {

	Dist.buckets = buckets;
	Dist.totalPopulation = popSize;
	Dist.numBuckets = numBuckets;
	Dist.min = min;
	Dist.max = max;

}

void Distribution::generateBuckets(std::string bucketName) {

//bucket reference
	std::ifstream bucketfile("../../../../src/bucket_reference.json");
	
	if (!bucketfile.is_open()) {
		std::cerr << "Could not open the file!" << std::endl;
		return;
	}

	json jbucket = json::parse(bucketfile);

	if (jbucket.contains("bucket_presets") && jbucket["bucket_presets"].contains(bucketName)) {
		
		const auto& buckets = jbucket["bucket_presets"][bucketName];
		int i = 0;
		std::cout << "buckets:\n";
		for (const auto& bucket : buckets) {
			int min = bucket["min"];
			int max = bucket["max"];
			std::vector<Pop> pops;

			Bucket b(min, max, pops);
			Dist.buckets.push_back(b);
			std::cout << "Min: " << min << ", Max: " << max << "\n";
			//buckets.push_back(b);
			i++;
		}
		//numBuckets = i;
		Dist.numBuckets = i;
	}
	else {
		std::cout << "bucket not found in JSON,\n";
	}
}

//void Distribution::generateDistribution(std::string distName) {
//	//distribution reference
//	std::ifstream distfile("../../../../src/distribution_reference.json");
//
//	if (!distfile.is_open()) {
//		std::cerr << "Could not open the file!" << std::endl;
//		return;
//	}
//
//	json jdist = json::parse(distfile);
//
//	if (jdist.contains("distribution_presets") && jdist["distribution_presets"].contains(distName)) {
//
//		const auto& dist = jdist["distribution_presets"][distName];
//
//		std::cout << "distribution:\n";
//		disttype = dist["type"];
//		std::cout << disttype << "\n" << std::endl;
//		
//	}
//	else {
//		std::cout << "\"normal_distribution\" not found in JSON,\n";
//	}
//	
//}

void Distribution::uniformDistribution(int popSize, int numBuckets) {
	if (Dist.numBuckets == 0) return;

	int freq = Dist.totalPopulation / Dist.numBuckets;
	Dist.totalPopulation = Dist.numBuckets * freq;
	for (auto& bucket : Dist.buckets) {
		bucket.setFrequency(freq);
		for (int i = 0; i < freq; ++i) {
			Pop p = {0};
			p.income = generateRandBound(bucket.getMin(), bucket.getMax());
			bucket.addPop(p);
		}
		
	}
}

int Distribution::getNumBuckets() const {
	return Dist.numBuckets;
}
int Distribution::getPopSize() const {
	return Dist.totalPopulation;
}

float Distribution::getStd() const {
	float std = 0;
	if (!Dist.buckets.empty()) {
		for (auto& bucket : Dist.buckets) {
			std += bucket.stdHelper(getMean());
		}
	}

	return sqrt(std / Dist.totalPopulation);
}

float Distribution::getMean() const {
	float mean = 0;
	if (!Dist.buckets.empty()) {
		for (auto& bucket : Dist.buckets) {
			mean += bucket.getBucketSum();
		}
	}

	return mean / Dist.totalPopulation;
}