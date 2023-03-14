// STD::VECTOR è meglio dei dynamic arrays. È come fare
// template<typename T, class Allocator = std::allocator<T>>   
// class vector;

#include <iostream>
#include <string>
#include <vector>

template <typename T>
void print_vector(const std::vector<T>& v, const std::string& s);
                      //oppure const T& v     



int main() {
  std::vector<int> v0{1, 2, 4};
  std::vector<int> v1(5, 4);  //quattro elementi =4

  print_vector(v0, "v0");
  print_vector(v1, "v1");
  v1 = v0;
  print_vector(v1, "v1 after copy");
  //posso copiare vettori di lung diversa(ma devono essere stesso tipo)

  
  //questa è std::initializer_list. non usare AUTO con {} sennò pensa a questa
  for (auto x : {7, 8, 9})
    v1.push_back(x);  // or v1.emplace_back(x);
  print_vector(v1, "v1 after push_back");

  
  for (auto i = 0u; i < v1.size(); ++i)  // .size()
    std::cout << "v[" << i << "] = " << v1[i] << std::endl;

  std::cout << v1[3] << " " << v1[78] << std::endl;       // no bounds checking
  std::cout << v1.at(3) << " " << v1.at(78) << std::endl; // bounds checking
  
  return 0;
}




template <typename T>
void print_vector(const std::vector<T>& v, const std::string& s) {
  std::cout << s << ": ";
  for (const auto& x : v)
    std::cout << x << " ";
  std::cout << std::endl;
}
