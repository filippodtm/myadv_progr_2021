#include <iostream>
// ALL of the 6 ctors, dtors can be set = default, or =delete

//If the user has defined (o deleted??) a copy constr--> the copy assignm, move con and assignment are not generated

struct X {
  int a = 5;  // in-class initialization
  double b;
  char c = 'c';
  X() = default;
  // in-class initializers if present, are used by the constructors
};


struct Y {
  int a = 77;
  double b;
  char c = 'c';
  Y(): a{5}   {}  // what it is written here wins the in-class initialization
  Y(const Y&) = delete;
  //to have unique pointers, we may need to delete the copy ctor / assgn
};



int main() {
  X x1;    // compiler-generated default ctor
  X x2{};  // compiler-generated default ctor that calls {} on uninitialized vars
  std::cout << x1.a << "--" << x1.b << "--" << x1.c << "\n";
  std::cout << x2.a << "--" << x2.b << "--" << x2.c << "\n\n";

  Y y1 ;    // default ctor 
  Y y2{};  // default ctor.  se nel default ctor dico di guardare solo a, le altre non le guarda comunque
  std::cout << y1.a << "   --  " << y1.b << "  --  " << y1.c << "\n";
  std::cout << y2.a << "  --  " << y2.b << "  --  " << y2.c << "\n";

  // Y y3{y2}; // error: call a deleted function

  return 0;
}
