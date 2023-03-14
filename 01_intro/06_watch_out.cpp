#include <iomanip>
#include <iostream>

int main() {
  // size matters!
  int a = 1;
  for (int i = 0; i < 33; ++i) {
    
    std::cout << a << std::endl;
    a *= 2;
  }

  // never ever use == (or !=) with floating point numbers

  // for (double d = 0.1; d != 1.0; d += 0.1)
  //   std::cout << d << std::endl;

  // std::cout << std::setprecision(50);
  // double d = 0;
  // for (int i = 0; i < 10; ++i) {
  //   d += 0.1;
  //   std::cout << d << std::endl;
  // }
  return 0;
}
