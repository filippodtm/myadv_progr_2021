#include <iostream>

namespace choose_a_name {
   int variable;
   namespace nested {
     void hello1();
     void hello2();
     void hello3();
   }  // namespace nested
}  // namespace choose_a_name



int main() {
 // variable = 42; // error
 choose_a_name::variable = 42;
 // hello1(); // error
 choose_a_name::nested::hello1();
 choose_a_name::nested::hello2();
 choose_a_name::nested::hello3();
 return 0;
}


void choose_a_name::nested::hello1() {
  std::cout << "hello1 from nested\n"
            << "variable is " << choose_a_name::variable << std::endl;
}


namespace choose_a_name {
  namespace nested {
    void hello2() {   //qui non serve choosename::nested::
      std::cout << "hello2 from nested\n"
                << "variable is " << variable << std::endl;
    }
  } 
} 

using namespace choose_a_name;  //meglio di no

void nested::hello3() {
  std::cout << "hello3 from nested\n"
            << "variable is " << variable << std::endl;
}
