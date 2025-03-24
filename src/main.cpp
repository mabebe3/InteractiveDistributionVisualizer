#include <SFML/Graphics.hpp>
#include "Distribution.hpp"
#include "Bucket.hpp"
#include "Pop.hpp"
#include <iostream>
#include <fstream>


int main()
{
    /*std::string distribution;

    std::cout << "Enter your distribution selection:";
    std::cin >> distribution;*/

    std::string bucket;

    std::cout << "Enter your bucket selection:";
    std::cin >> bucket;

    std::vector<Bucket> buckets;

    Distribution d(buckets, 100000, 10, 0, 100000);
    d.generateBuckets(bucket);
    //d.generateDistribution(distribution);
    d.uniformDistribution(d.getPopSize(), d.getNumBuckets());

    std::cout << "Distribution complete. \n";

    std::cout << "Distribution mean: " << d.getMean() << "\n";
    std::cout << "Distribution standard deviation: " << d.getStd() << "\n";

    return 0;

}
