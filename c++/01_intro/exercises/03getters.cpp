// OK FUNZIONA
#include <iostream>

void getint(){
    int n;
    while(!(std::cin >> n))
      //ok se mettevo while(std::cin>>i) leggeva finchè va bene
    {
      std::cin.clear();
      std::cin.ignore();
    }
}

void getdouble(){
    double n;
    while(!(std::cin >> n)) 
    {
      std::cin.clear();
      std::cin.ignore();
    }
}



int main(){
  char choice;
  
  std::cin >> choice;
  switch(choice)
    {
    case 'i':  //non mettere "" sennò lo prende come string e non va lo switch
      getint();
      break;
    case 'd': 
      getdouble();
      break;
    default:
      std::cout << "bruh" << "\n";
      break;
    }
  return 0;
}


