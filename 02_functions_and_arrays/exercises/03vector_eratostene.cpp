//
#include <iostream>

int main(){
  std::cout << "inserisci N: ";
  int n;
  std::cin >> n;

  int* numeri {new int[n+1]}; // 0,1,2,...n
  int* cand {new int[n+1]};
  for (int i{0}; i <=n; ++i){
    numeri[i]= i;
    cand[i] = i;
  }
  cand[1]=0;
  //std::cout << "\n" << numeri[1] << std::endl;

  for (int p{2}; p<=n; ++p){
    if (cand[p] != 0){
      for (int i{2}; i*p <= n; ++i) //tolgo da cand i multipli di p
	cand[i*p] = 0;
    }
  }

  for (int j{2}; j<=n; ++j){
    if(cand[j] != 0)
      std::cout << cand[j] << "\n";
  }
  
  delete[] numeri;
  delete[] cand;
}
