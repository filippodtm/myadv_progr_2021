#include <iostream>
#include <sstream>
#include <string>

                                     // argv è array of strings?
int main(int argc, char* argv[]) {   //--oppure char** argv
  for (auto i = 0; i < argc; ++i)
    std::cout << "argv[" << i << "] = " << argv[i] << std::endl;

  
  unsigned int a;  //questo se suppongo che il primo elem sia per forza int!
  {
    std::istringstream s {argv[1]};
    s >> a;
  }
  std::cout << "a is " << a << std::endl;


  

  // std::stoi  //string to integer, str to longint...ecc  ??
  // std::stol
  // std::stoll
  // std::stof
  // std::stod
  // std::stoull
  a = std::stoul( argv[1]);
  std::cout << "a is " << a << std::endl;

  return 0;
  
}
