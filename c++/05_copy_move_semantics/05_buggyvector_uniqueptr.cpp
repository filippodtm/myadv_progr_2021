#include <iostream>
#include <memory>
// REFINE THE TYPE VECTOR part III
// UNIQUE POINTERS:
// T* .get
// void reset
// T* release


template <typename T>
class Vector {
  std::unique_ptr<T[]> elem;
  std::size_t _size;

  public:
  explicit Vector(const std::size_t length) : elem{new T[length]{} }, _size{length} {}

  const T& operator[](const std::size_t& i) const { return elem[i]; }
  T& operator[](const std::size_t& i) { return elem[i]; }

  std::size_t size() const { return _size; }
  
  const T* begin() const { return elem.get(); } //elem è uniquep quindi uso .get
  T* begin() { return elem.get(); }

  const T* end() const { return elem.get() + _size; }
  T* end() { return elem.get() + _size; }
};



int main() {
  Vector<double> v1{7};
  // Vector<double> v2{v1}; // default copy ctor calls a deleted function
  //copy cons and assignment sono eliminati :(  
  
  return 0;
}
