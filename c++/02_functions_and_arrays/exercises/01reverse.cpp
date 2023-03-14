//ok FUNZIONA
#include <iostream>


template <typename T>
T* f1(const std::size_t n){
  T* array1 = new T[n];  //dynamic array    (array1 è locale?)
  std::cout << "insert the elements of the array: \n";
  for (std::size_t i{0}; i<n; ++i)
      std::cin >> array1[i];
  return array1;
}   

template <typename T>
void f2(T* array1, std::size_t n){
  
  for(std::size_t j{0}; j<n; ++j){
    std::cout << array1[n-j-1] <<"\n";
  }
}


int main(){
  std::cout<<"insert length: ";
  std::size_t n;
  std::cin >> n;
  auto array1= f1<double>(n); //potrebbe non andare benissimo
  f2(array1, n);
  delete[] array1;
}

