#include <iostream>

template <typename T>
void print_sentinel(const T* a, const std::size_t l);


int main() {
  int a{8}, b{7};
  int* pi{&a};

  const int* pc {&a}; //POINTER TO CONST (leggere da dx a sx)
  // *pc = 7;   error
  a = 15;  // I can obviously change a

  int* const cp{&a}; //CONST POINTER
  a = b;
  *cp = 33;
  // cp = &b;   // error

  const int* const cpc{&a};  //const tutto
  // *cpc = 0;  // error
  // cpc = &n;  // error
  a = 99;

  int aa[4]{1,2,3, 4};
  *aa =0;
  print_sentinel(aa, 4);
  return 0;
}


//(static) ARRAY = POINTER TO CONST(?)
template <typename T>
void print_sentinel(const T* a, const std::size_t l) {
  const T* const end {a + l};  //come faccio ptr+l:
  //faccio l salti ognuno di dim "dim. di tipo T" e arrivo un posto dopo la fine
  for (; a != end; ++a)   //a non è un const pointer. posso cambiare a
    std::cout << *a << std::endl; 
}
