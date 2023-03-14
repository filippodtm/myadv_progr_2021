#pragma once

#include <iostream>

template <class T = double>
void dummy() {
  T t{};
  std::cout << t << ": dummy\n";
}


//per template va bene one def rule con tutto
