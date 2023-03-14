//
#include <iostream>

int main(){
  int a{8};
  int* p1{&a};
  void* pv{p1};
  //pv= nullptr;  //se metto questa o no non cambia nulla, comunque 0 
  std::cout << pv <<" = pv" <<std::endl;
  return 0;
  
}  
