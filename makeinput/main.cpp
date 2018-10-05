#include <cstdint>
#include <iostream>
#include <random>

int main(int argc, char **argv) {

  /* Initialise. Do this once (not for every
     random number). */
  std::random_device rd;
  std::mt19937_64 gen(rd());

  /* This is where you define the number generator for unsigned long long: */
  std::uniform_int_distribution<uint64_t> dis;

  int n = 500000;
  int m = 500000;

  std::cout << n << " " << m << "\n";

  for (int i = 0; i < m; ++i)
    std::cout << 1 + i << " " << 2 << "\n";

  for (int i = 0; i < n; ++i)
    std::cout << 2 + i << " " << 4 << "\n";
  return 0;
}