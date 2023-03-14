#include <iostream>

//OVERLOADING does not work through inheritance (se non metto using)
//

struct foo {
  void f(int x) { std::cout << "int " << x << std::endl; }
};

struct bar : public foo {
  using foo::f;  // brings all foo::f to this scope. Non voglio override. 
  void f(char x) { std::cout << "char " << x << std::endl; }
};

int main() {
  bar b;
  b.f('a');
}


//  --SDM--
 
