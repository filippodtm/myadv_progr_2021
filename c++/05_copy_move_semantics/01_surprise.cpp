#include <iostream>
#include <utility> 
// non abbiamo constructors nè destr, non abbiamo quindi l'assignment operator =
// ilcompiler genera autom dei constructors


struct X {
  char member1;  //deve essere un built in
};

int main() {
  X x1;                 // default ctor
  X x2 {x1};             // copy ctor
  X x3{std::move(x2)};  // move ctor
  X x4{};               // default ctor calling {} to each member
  x4 = x3;              // copy assignment
  X x5;                 // default ctor
  x5 = std::move(x4);   // move assignment
  std::cout << x5.member1 << std::endl;  // what do you expect??
  return 0;
}



// std:move is a static cast from l-val to a r-val reference; qui il compilatore non fa davvero std::move, ma conosce già la rval ref (Le rval ref sono built in)

// Foo(const Foo&); copy constructor 
// Foo(Foo&&);      move constructor    (Foo&& è una r-value ref)
// foo& operator=(const foo&);  copy assignment
// foo& operator=(foo&&);      move assignment 

//un default constuctor sintetizzato dal compilatore, senza {} lascia le variabili built-in non inizializzate. Diverso se uso le {} 
