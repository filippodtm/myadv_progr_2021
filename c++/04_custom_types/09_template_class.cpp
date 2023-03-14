#include <iostream>
#include <string>
//WE WANT TO REDEFINE THE TYPE VECTOR (vedi più avanti 05../04_buggyvector)


template <typename T>
class Vector {
  T* elem;       //(!A)
  std::size_t  _size;
  
  public:
  Vector(const std::size_t dimens) : elem{new T[dimens]} , _size{dimens}   {} 
  ~Vector() { delete[] elem;}  //automatically release the acquired memory (RAII: no memory leaks)

  std::size_t size() const { return _size; }
  //se non metto const qui il compilatore non va: pensa che size() cambi v (solo con member functions)
  //Con const in mezzo, il compiler mette const davanti a riga 8-9 e controlla

  T& operator[](const std::size_t i) { return elem[i];}     //{non so perchè c'era ++i; dentro
  const T& operator[](const std::size_t i) const { return elem[i]; }   //(B)
  // try to comment this line. succede che op overloading di << da errore (perchè prende const vector)
  // (se non metto CONST anche davanti potrebbe succedere che poi cambio il valore ma compila lo stesso)

  //ci servono begin, end per range-based for loop
  const T* begin() const { return elem; }   
  T* begin() { return elem; }        
  const T* end() const { return elem + _size; }
  T* end() { return elem + _size; }

  friend std::ostream& operator<<(std::ostream& os, const Vector& v){
    os<< v.elem << ": ";
    for (const auto& x : v)
      os << x << " ";
    os << std::endl;
    return os;
   }
  };


//template <typename T>
//std::ostream& operator<<(std::ostream& os, const Vector<T>& v){    
//    os<< v.elem << ": ";
//    for (const auto& x : v)                           CAZZATA, NON SI PUO METTERE FUORI QUA
//      os << x << " ";
//      os << std::endl;
//    return os;
//}


template <typename T>
void foo(const Vector<T>& x) {
  auto p = x.begin();
  ++p;}


//template <typename T>
//std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
  //e manca il riferimento dentro la class però questo compila comunque
//  for (auto i = 0u; i < v.size(); ++i)
//    os << "v[" << i << "] = " << v[i] << std::endl;
//  return os;
//}



int main() {
  Vector<double> v{10};
  for (auto i = 0u; i < v.size(); ++i)
    v[i] = i;
  std::cout << v << std::endl;

  Vector<double>* pv{&v};

  (*pv)[0] = -99.999;
  pv->operator[](1) = 77777.3333;  // or I call the function by name
  std::cout << *pv << std::endl;
  
  Vector<double>& rv{v};
  rv[5] = 555;
  std::cout << v << std::endl;

  return 0;
}

//OCCHIO: il compiler per fare check che non sia cambiato nulla in (A) mette   // T* const elem 

//(è un const pointer) quindi potrei avere in (B) una funz che cambia effettivamente una componente e a lui andrebbe bene!
