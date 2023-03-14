#include <cstring>  //  serve per strcmp (string comparison)
#include <iostream>

int func1(const char* a);
int func2(const char* a);
void func3(const char* a);



int main() {
  int a{8};
  int* pi{&a};
  char** ppc;  //è pointer to pointer to char?

  int* ap[7];  //static array of pointers

  void* pv{pi};  //void* can point to whatever
  // *pv;      we cannot dereference void*
  // ++pv;    // cant increment: he doesnt know how big the pointed obj is
  int* pi2 {static_cast<int*>(pv)};
  //static cast is done at compiletime
  
  pv = ppc;
  pv = ap;     //qui se cambio pv non cambia pi e vicev. (se cambio "a" si..)
  pv = pi;

  pi = nullptr;
  ppc = nullptr;                    //cose robe
  // ap = nullptr;  // error, static array è simile a const pointer (SDM)
  ap[0] = nullptr;
  int** bbb;
  bbb = ap;
  //pv = nullptr;
  pi2 = 0;  // older codes. gets the nullptr. please don't do it
  // pi = NULL; // please don't do it


  
  double* da{new double[5]{}};
  delete[] da;  // DANGLING pointer
  da = nullptr;  //mettere subito nullptr per evitare fastidi


  
  if (pi != nullptr)
    std::cout << "pi is not nullptr and I can dereference it " << *pi
              << std::endl;
  if (pv)     //same as before, any nonzero number is converted to true
    std::cout << "pv is not nullptr and I can dereference it " << *pi
              << std::endl;
  if (pv == nullptr)
    std::cout << "pv is nullptr and I CANNOT dereference it \n";
  //uguale fare
  if (!pv)
    std::cout << "pv is nullptr and I CANNOT dereference it \n";

  
  //diff tra pointer to void e nullptr?

  
  
  // STRINGS are special type of char[] ie: (static?) array of chars
  char word[]{"Hello"};
  char word2[]{'H', 'e', 'l', 'l', 'o', 0};   //bisogna 0
  if (strcmp(word, word2) == 0)
    // word == word2 is implementation-dependent (it might
     // compare the two pointers, i.e. the addresses of word and word2)
       std::cout << "same\n";
  else
       std::cout << "different\n";



  
  
  //POINTERS TO FUNCT
  int (*fp)(const char*);
  //fp è un punt che può puntare solo a funzioni che danno un int e prendono char*

  fp = func1;     //con o senza &
  fp("hello"); 
  fp = &func2;
  fp("world");
  // fp = func3; // error: wrong signature

  auto xx = func3;
  xx("auto");

  decltype(&func3) x = func3; //decltype è come AUTO
  x("decltype");

  return 0;
}





int func1(const char* a) {
  std::cout << "1111: " << a << std::endl;
  return 1;}

int func2(const char* a) {
  std::cout << "2222: " << a << std::endl;
  return 2;}

void func3(const char* a) {
  std::cout << "3333: " << a << std::endl;
}
