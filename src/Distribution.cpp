#include "Pop.hpp"
#include "Bucket.hpp"
#include "Distribution.hpp"
#include <fstream>
#include <iostream>
#include <vector>
//#include <cmath>
#include "json.hpp"
using json = nlohmann::json;

std::vector<Bucket> buckets;
str::string disttype;

Distribution::Distribution( std::vector<Bucket> buckets , int popSize, int min, int max) : Dist = { buckets , popSize ,min , max } {
//// allocate dist vector
//	std::vector<Bucket> buckets;
//// set population
//	totalpopulation =  popSize;
//// set bounds
//	this->min = min;
//	this->max = max;
}

void Distribution::generateBuckets(str::string bucketName) {

//bucket reference
	std::ifstream file("bucket_reference.json");

	if (!file.is_open()) {
		std::cerr << "Could not open the file!" << std::endl;
		return 1;
	}

	json jbucket;
	file >> jbucket;

	if (jbucket.contains("bucket_presets") && jbucket["bucket_presets"].contains("normal_dist_test")) {
		
		const auto& buckets = bucketj["bucket_presets"]["normal_dist_test"];

		std::cout << "normal_dist_test buckets:\n";
		for (const auto& bucket : buckets) {
			Bucket b = { bucket["min"],bucket["max"],std::vector<Pop> p = {} };
			std::cout << "Min: " << min << ", Max: " << max << "\n";
			buckets.push_back(b);
		}
			
	}
	else {
		std::cout << "\"normal_dist_test\" not found in JSON,\n";
	}
	return 0;
}

void Distribution::generateDistribution(str::string distName) {
	//distribution reference
	std::ifstream file("distribution_reference.json");

	if (!file.is_open()) {
		std::cerr << "Could not open the file!" << std::endl;
		return 1;
	}

	json jdist;
	file >> jdist;

	if (jdist.contains("distribution_presets") && jdist["distribution_presets"].contains("normal_distribution")) {

		const auto& dist = jdist["distribution_presets"]["normal_distribution"];

		std::cout << "distribution:\n";
		disttype = dist["type"];
		std::cout << disttype << "\n" << endl;
		

	}
	else {
		std::cout << "\"normal_distribution\" not found in JSON,\n";
	}
	return 0;
}
