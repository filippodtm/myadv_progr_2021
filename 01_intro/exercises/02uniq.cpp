//FUNZIONA OK
#include <iostream>
#include <string>
//usa "./a.out < nomefile"  poi da command line

int main(){
  
  std::string rigapreced{};
  unsigned int repcount{0};  
  //

  for(std::string riga; std::getline(std::cin, riga); )  //prende da cin e mette in "riga"
    {
      if(riga == rigapreced)
        { ++repcount;
	}
      else{
	if(repcount>1)
	  std::cout<< "[rip "<<repcount<< " volte]" << rigapreced;
	else
	  std::cout << rigapreced;
	std::cout << std::endl;
	repcount=1;
        rigapreced = riga;
      }
    }

}
