//DYNAMIC ARRAYS (built-in)
#include <iostream>


int main() {
  std::cout << "Please insert array length: ";
  std::size_t n;
  std::cin >> n;
  int* da { new int[n] };  // allocated on the HEAP, or free-store

  for (std::size_t i{0}; i < n; ++i)
    da[i] = i * 10;
  for (std::size_t i{0}; i < n; ++i)
    std::cout << "da[" << i << "] = " << da[i] << std::endl;

  delete[] da;   // IMPO!!
  return 0;
}

//qui fine lezione 18.10.21
