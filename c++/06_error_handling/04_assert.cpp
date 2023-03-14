#include <cassert>
#include <cmath>
#include <iostream>

#include "ap_error.hpp"

//asserts "non sono mai abbastanza". possono essere preconditions/postconditions
//se compilo con -DNDEBUG non succede niente e il compiler lo cambia in qualcosa che non fa nulla

double square_root(const double d);

int main() {
  try {
    std::cout << "please insert a number\n";
    double number;
    std::cin >> number;
    double d = square_root(number);
    std::cout << "square root of " << number << " is " << d << '\n';
    return 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  } catch (...) {
    std::cerr << "Unknown exception. Aborting.\n";
    return 3;
  }
}

double square_root(const double d) {
  // test the pre-conditions
  assert(d >= 0 && d <= 50);  // provided by C, no execeptions

  //AP_ASSERT(d >= 0 && d <= 50) << "d should be in the range [0,50]";

  // AP_ASSERT_IN_RANGE(d,0,50);
  return sqrt(d);
}
