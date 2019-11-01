#include "random.h"

RandomNumbers::RandomNumbers(unsigned long int s) : seed(s) {
	if (seed == 0){
		std::random_device rd;
		seed = rd();
	} 
	rng = std::mt19937(seed);
}

void RandomNumbers::uniform_double(std::vector<double>& vec, double lower, double upper){
	std::uniform_real_distribution<double> uni_distrib(lower,upper);
	for (size_t i = 0; i < vec.size(); ++i){
		vec[i] = uni_distrib(rng);
		}
	return;	
}

double RandomNumbers::uniform_double(double lower, double upper){
	std::uniform_real_distribution<double> uni_distrib(lower,upper);
	return uni_distrib(rng);
}

void RandomNumbers::poisson(std::vector<int>& vec, double mean){
	std::poisson_distribution<int> pois_distrib(mean);
	for (size_t i = 0; i < vec.size(); ++i){
		vec[i] = pois_distrib(rng);
		}
	return;	
}

int RandomNumbers::poisson(double mean){
	std::poisson_distribution<int> pois_distrib(mean);
	return pois_distrib(rng);	
}

void RandomNumbers::normal(std::vector<double>& vec, double mean, double sd){
	std::normal_distribution<double> norm_distrib(mean, sd);
	for (size_t i = 0; i < vec.size(); ++i){
		vec[i] = norm_distrib(rng);
		}
	return;
}

double RandomNumbers::normal(double mean, double sd){
	std::normal_distribution<double> norm_distrib(mean, sd);
	return norm_distrib(rng);
}
