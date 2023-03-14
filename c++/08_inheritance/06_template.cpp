#include <iostream>

template <typename T>
struct Base {
  void foo() const { std::cout << "base foo" << std::endl; }
};

template <typename T>
struct Derived : public Base<T> {
  void bar() const { Base<T>::foo(); }  //senza this funzia (anche si)
};                   // this->foo();   forse meglio questa se la parent è private (boh?)     

int main() {
  Derived<int> d;
  d.bar();
}  





/* IF WE WORK WITH A TEMPLATED PARENT CLASS WE HAVE TO USE "THIS->"
 anche se il template non è davvero usato nella parent
*/
