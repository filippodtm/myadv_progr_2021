#include <chrono>
#include <iostream>

//constexpr function CAN be (but isn't always) evaluated at comp.time: per essere sicuro metto
//                                                                     constexpr x=fib... 
//Can only take "literals" (built-in types) as input (BOH)
constexpr std::size_t fib(const unsigned int x) {
  return (x < 2) ? x : fib(x-1) + fib(x-2);
   // if (x < 2) return x;
   // else {
   //   return fib(x-1) + fib(x-2);
   // }
}

//questa sicuro a runtime
std::size_t fib_rt(const std::size_t x) { 
  if (x < 2)
    return x;
  return fib(x-1) + fib(x- 2);
}


//TEMPLATE METAPROGRAMMING
template <unsigned i> //templates are TYPENAME or integers (and must be known at comptime)
constexpr std::size_t fib_t() {
  return fib_t<i-1 >() + fib_t<i-2>();
}

template <>
constexpr std::size_t fib_t<0>() {
  return 0;
}
template <>
constexpr std::size_t fib_t<1>() {
  return 1;
}

//IF CONSTEXPR (versione >=17) permette di valutare l'if già a compile time
//(con IF entrambe le alternative vengono implementate a comp.t. e poi a runtime lui sceglie)
#if __cplusplus > 201700L

template <unsigned i>
constexpr std::size_t fib_t17() {
  if constexpr (i < 2)
    return i;
  else {              // very important, qui non puo mancare
    return fib_t17<i-1>() + fib_t17<i-2>();
  }
}
#endif





constexpr unsigned int num{24};
int main() {
  {
    auto t0 = std::chrono::high_resolution_clock::now(); //to measure time
    constexpr auto x = fib(num);
    auto t1 = std::chrono::high_resolution_clock::now();
    auto elapsed =                                         // SDM
        std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
    std::cout << "constexpr: " << x << " [" << elapsed.count() << " us]"
              << std::endl;
  }
  {
    auto t0 = std::chrono::high_resolution_clock::now();
    auto x = fib_rt(num);
    auto t1 = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
    std::cout << "run time: " << x << " [" << elapsed.count() << " us]"
              << std::endl;
  }
  {
    auto t0 = std::chrono::high_resolution_clock::now();
    auto x = fib_t<num>();
    auto t1 = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
    std::cout << "templatesss: " << x << " [" << elapsed.count() << " us]"
              << std::endl;
  }

#if __cplusplus > 201700L
  {
    auto t0 = std::chrono::high_resolution_clock::now();
    auto x = fib_t17<num>();
    auto t1 = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
    std::cout << "c++17: " << x << " [" << elapsed.count() << " us]"
              << std::endl;
  }
#endif

  return 0;
}

//SO: templates are more robust and let you work with higher input numbers
