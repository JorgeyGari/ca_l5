#ifndef ILP_GENERATE_HPP
#define ILP_GENERATE_HPP

#include <random>
#include <vector>

// Generates a vector of n random values using rng as random engine
std::vector<double> generate(std::mt19937_64 rng, long n);

#endif //ILP_GENERATE_HPP
