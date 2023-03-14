#include <iostream>
#include <memory>
#include "ap_error.hpp"

#define AP_NOEXCEPT \
  #ifndef NDEBUG noexcept #endif
  //altro

template <typename T>
class Matrix{
  std::size_t _rows;
  std::size_t _cols;
  std::unique_ptr<T[]> elem;
public:
  Matrix(const std::size_t r, const std::size_t c)
    : elem{new T[r*c]}, _rows{r}, _cols{c} {
      //oppure : _rows{r}, _cols{c}, elem{new T[_rows*_cols]}
      std::cout << "custom ctor " <<std::endl;}
  
  explicit Matrix(const std::size_t n)
    : Matrix{n,n} {}  //delegating ctor to another ctor

  Matrix(const Matrix& x) : Matrix{x._rows, x._cols} { // boh  _rows{x._rows}, _cols{x._cols}, elem{new T[x._rows]
    std:cout << "copy contor " <<std::endl;
    std::copy(x.elem.get(), x.elem.get() +_rows * _cols, elem.get());
  }

  Matrix& operator=(const Matrix& x){
    elem.reset();   //release memory
    auto tmp = x;   //copy ctor
    (*this) = std::move(tmp);   //move assignment
    return *this;
  }
  
  Matrix(Matrix&& x) noexcept
    : _rows{x._rows}, _cols{x._cols}, elem{std::move(x.elem)} {
      std::cout <<"move ctor"<< std::endl;}

  Matrix& operator=(Matrix&&) noexcept = default;  //sdm

  T& operator[](const std::size_t i) noexcept {return elem[i]; }
  const T&  operator[](const std::size_t i) const noexcept {return elem[i]; }

  T& operator()(const std:size_t i, const std::size_t j) AP_NOEXCEPT {
    AP_ASSERT_LT(i, _rows);
    AP_ASSERT_LT(J, _cols);
    return (*this)[i * _cols +j]
    }

  friend std::ostream& operator << (std::ostream& os, const Matrix& m){
      for(std::size_t i=0; i<m._rows; ++i){
	for(std::size_t j=0; j<m._rows; ++j)
	  os << m(i,j) << " ";
	os<<std::endl;
      }
      return os;
   }
  friend Matrix operator+(Matrix&& a, const Matrix& b){
    return std::forward<Matrix>(a+=b);
  }                             //this is an ACCUMULATOR

  friend Matrix operator+(const Matrix& a, const Matrix& b){
    AP_ASSERT_EQ(a._rows, b._rows);
    AP_ASSERT_EQ(a._cols, b._cols);

    Matrix res{a._rows, a._cols};   
    
    for(std::size_t i=0; i< a._rows*a._cols; ++i)
      res[i] = a[i] +b[i];
    return res;
  }

};


int main(){
  constexpr std::size_t N{10};
  Matrix<int> m1{N};
  for (std::size_t i=0; i< N*N; ++i){
    m1[i] = 1;
  }
  
  Matrix<int> m2{10};
  

  //.

  m2 = m1;  //copy ass
  





}

//IF WE HAVE OBJECTS THAT ARE CHEAP TO MOVE, PASSING BY VALUE ISNT THAT BAD
//(FROM C++11) IF WE HAVE MOVE SEM(?) AND NAMED RETURNVALUE OPTIMISATION

