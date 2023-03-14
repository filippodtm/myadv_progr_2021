#ifndef __class__
#define __class__
//questoserve perchè ogni header deve essere incluso una volta sola. certe volte alcuni header sono annidati quindi ocio. Oppure basta mettere pragma once

#include <iostream>

struct A {
  int a;
  A() { std::cout << "A ctor\n"; }
};

// A::A() { std::cout << "A ctor\n"; } // why not?

#endif
