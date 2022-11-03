#include "generate.hpp"

#include <chrono>
#include <iostream>
#include <random>
#include <bit>

double average_positive(const std::vector<double> & v) {
  double sum = 0.0;
  int n=0;
  const auto max = std::ssize(v);
  for (long i=0; i<max; ++i) {
      uint64_t mask = (v[i] > 0) ? 0xffffffffffffffff:0x0;
      uint64_t x = std::bit_cast<uint64_t>(v[i]);
      x &= mask;
      double xd = std::bit_cast<double>(x);
      sum += xd;
      n = (v[i] > 0) ? n + 1:n;
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