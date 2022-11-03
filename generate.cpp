#include "generate.hpp"

std::vector<double> generate(std::mt19937_64 rng, long n) {
  std::uniform_real_distribution valgen{-100.0, 100.0};
  std::vector<double> r;
  r.reserve(n);
  for (int i = 0; i < n; ++i) {
    r.push_back(valgen(rng));
  }
  return r;
}

