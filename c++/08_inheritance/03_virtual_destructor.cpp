#include <iostream>

struct Base {
  Base() { std::cout << "Base \n"; }
   ~Base() { std::cout << "~Base\n"; } //senza virtual deletava solo il parent
};

struct Derived : public Base {
  Derived() { std::cout << "Derived\n"; }
  ~Derived() { std::cout << "~Derived\n"; }
};

int main() {
  { Derived d; }

  std::cout << "\n\npointers\n";
  Base* p = new Derived;
  delete p;

  return 0;
}


//dynamic binding: virtual functions
