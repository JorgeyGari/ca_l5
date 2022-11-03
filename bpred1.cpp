#include "generate.hpp"

#include <chrono>
#include <iostream>
#include <random>

double average_positive(const std::vector<double> & v) {
  double sum = 0.0;
  int n=0;
  const auto max = std::ssize(v);
  for (long i=0; i<max; ++i) {
    if (v[i]>0) {
      sum += v[i];
      n++;
    }
  }
  return sum / static_cast<double>(n);
}

int main() {
  using namespace std::chrono;
  std::mt19937_64 gen{0};
  constexpr int max = 1'000'000;
  auto v = generate(gen, max);

  auto t1 = std::chrono::high_resolution_clock::now();
  auto avg1 = average_positive(v);
  auto t2 = high_resolution_clock::now();

  std::cout << "Average = " << avg1 << '\n';
  std::cout << "Averaging time: " << duration_cast<microseconds>(t2 - t1).count() << " us\n";
}