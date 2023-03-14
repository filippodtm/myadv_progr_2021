#include <iostream>
#include <memory>

#include "ap_error.hpp"

//perse cose ~h15.10 su destr che ha scritto

//funzione definita con noexcept =/= funzione senza noexcept


class Vector {
  std::unique_ptr<double[]> elem;
 public:
  //noexcept per dire che sono sicuro che non ci saranno exceptions
  Vector() noexcept= default;
  Vector(const unsigned int l) : elem{new double[l]} {} //qui non posso mettere il mark noexcept, perchè new potrebbe lamentarsi (PRENDE IN INGRESSO QUALCOSA)
  Vector(Vector&&) noexcept = default;  //copy costr (move?)
  Vector& operator=(Vector&&) noexcept = default;
  double& operator[](const unsigned int i) noexcept { return elem[i]; }
  const double& operator[](const unsigned int i) const noexcept {
    return elem[i];
  }

  ~Vector() noexcept { std::cout << "~Vector\n"; } //se un destr manda exceptions è undefined behavior
};


class ManyResources {
  std::unique_ptr<double[]> ptr;
  Vector v;
 public:
  ManyResources() : ptr{new double[5]}, v{3} {
    std::cout << "ManyResources ctor\n";
    AP_ERROR(false) << "I am simulating something wrong.\n";
  }
  ~ManyResources() noexcept { std::cout << "~ManyResources\n"; }
};




int main() {
  try {
    std::unique_ptr<int[]> up{new int[7]};  // RAII - resource acquisition is initialization
    ManyResources mr;
    //nella riga qui sopra non c'e problema con ..??
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;

  } catch (...) {
    std::cerr << "Unknown exception. Aborting.\n" << std::endl;
    return 2;
  }
  return 0;
}
