#include <iostream>
// REFINE THE TYPE VECTOR part II (VEDI ANCHE /04../09_templateclass)
//PROBLEMI QUA: 1. v1 e v2 restano collegati
//              2. il destructor elimina due volte stessa roba

template <typename T>
class Vector {
  T* elem;
  std::size_t _size;

  public: 
  explicit Vector( const std::size_t length) : elem{new T[length]{}}, _size{length} {}
  //explicit davanti a constructors che vengono invocati con  UN argomento (che fanno implicitamente una conversione da "tipo dell'argument" a "tipo della classe")
  ~Vector() { delete[] elem; } //

  const T& operator[](const std::size_t& i) const { return elem[i]; }
  T& operator[](const std::size_t& i)  { return elem[i]; }

  std::size_t size() const { return _size; } 

  // range-b for
  const T* begin() const { return elem; }
  T* begin() { return elem; }
  const T* end() const { return elem + size(); }
  T* end() { return elem + size(); }     // pointer al primo elemento fuori
};


void funz(const Vector<int>& v){
  std::cout << v.size() << std::endl;
}



int main() {
  Vector<int> v1{3};
  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;
  
  //funz(1);  // non dà errore, il cons converte implicitam il numero stdsize_t in un vector. Non rischiamo questo bug mettendo explicit, cosi questa conversione accade solo quando sto effettivamente costruendo  un vector
  
  std::cout << "v1: ";
  for (const auto x : v1)
    std::cout << x << " ";
  std::cout << std::endl;

  Vector<int> v2{v1};  // non bene

  std::cout << "v2 after default copy ctor: ";
  for (const auto x : v2)
    std::cout << x << " ";
  std::cout << std::endl;

  v1[0] = 99;

  std::cout << "v2 after v1 has been changed: ";
  for (const auto x : v2)
    std::cout << x << " ";
  std::cout << std::endl;

  v2[1] = -999;

  std::cout << "v1 after v2 has been changed: ";
  for (const auto x : v1)
    std::cout << x << " ";
  std::cout << std::endl;

  return 0;
}
