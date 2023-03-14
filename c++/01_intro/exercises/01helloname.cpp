#include <iostream>
#include <string>

int main(){
  std::cout << "Insert your name and age:\n";
  std::string name;
  unsigned int age;
  
  std::cin >> name >> age;
  std::cout << "Hello, " << name << " [" << age << "]\n";
  return 0;
}



//senza main: dà cin , cout non ben definiti tipo
// con typos: individua riga, dice non declared
// senza ";" -> dice expected ;
// senza iostream -> std::cout is defined in <iostream>
// dichiarando int DOUBLE{0}  "expected primary expression before int" (??)
