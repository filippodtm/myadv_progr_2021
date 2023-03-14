#include <iostream>
#include <string>
// DEFAULT CONSTRUCTOR FOR BUILT-INs VS   STD::STRING,  AGGREGATE INIT.


struct S {
  int a;
  double b;
  std::string s;  // default ctor of string sets s to empty string
};


int main() {
  S s1 ;  //calls default constructor (a,b builtin -> are left uninitialized)

  S s2 {1, 2.3, "alberto"};  // if there are no custom ctors I can directly
                             // initialize the members. Note that I need
                              // access (i.e. they must be public).
  // "Aggregate initialization":

  S s3 {};  //IMPO: calls {} on each member: S s3 { {}, {}, {} };

  std::cout << s1.a << "        " << s1.b << "      " << s1.s << "\n";
  std::cout << s2.a << "          " << s2.b << "      " << s2.s << "\n";
  std::cout << s3.a << "         " << s3.b << "      " << s3.s << "\n";

  return 0;
}
