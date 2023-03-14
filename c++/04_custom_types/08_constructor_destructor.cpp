#include <iostream>
#include <string>

//constructors dont have a return type; hanno stesso nome del struct.

//Funzioni definite dentro la classe sono inlined (senza jump)
//Per funzioni corte conviene inlined

struct Foo {
  int _i;
  double _d;
  std::string _s;

  Foo(const int intero, const double doppio, const std::string& stringa);   // custom constructor
  Foo();     // DEFAULT constructor
  ~Foo();    // destructor
};



// _i, _d, _s must be init. the same order they have been declared        
Foo::Foo(const int intero, const double doppio, const std::string& stringa) : _i{intero}, _d{doppio}, _s{stringa}      
{
  _i= intero +10 ; //se le 3 righe sopra sono commentate qui non posso usare {}()
          //se _i è builtin, non succ nulla. se è custom o std, il default
          //constructor è invocato automaticam. quindi(?) è meglio 3 righe sopra
  std::cout << "custom ctor\n";
  // if you want/need you can use _i, _d, _s and change their value
  // don't use {} because this notation is reserved for the
  // construction of the variables and at this point they have already
  // been constructed
}


Foo::Foo() {
  std::cout << "default ctor\n";  // what happens to our member variables? restano uninitialized
}

Foo::~Foo() {
  std::cout << "dtor\n";
}

std::ostream& operator<<(std::ostream& os, const Foo& f) {
  os << f._i << " " << f._d << " " << f._s << std::endl;
  return os;
}



int main() {
   Foo f0;    // call default ctor
   Foo f1{};  // call default ctor
   // Foo f2(); // compiler error 

   Foo f2(8, 2.2, "hello");   //USARE LE GRAFE NEL DUBBIO
   std::cout << "f0: " << f0 << "f1: " << f1 << "f2: " << f2<< std::endl;

   // the destructor is called when the variable goes out of scope
   return 0;
}
