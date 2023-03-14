#include <array>
#include <iostream>
#include <vector>

// p.print() è come point::print()
// come point::print(&p)  o  point::print(point  *this)   


struct Point_s {
  double x;
  double y;
};  // ;!
//voglio estendere la definizione di std::cout<<x con operator<<(std::cout, x) per un elemento x della struct Point_S

std::ostream& operator<<(std::ostream& os, const Point_s& p) {   //<< ha bisogno di DUE args
  os << "Struct. x = " << p.x << "; y = " << p.y << std::endl;
  return os; 
}


class Point_c {
  double x;
  double y;
  //(se voglio DEFINIRE fuori da class, lascio solo friend [dichiaraz..] dentro
  // Rischio però, meglio definire OPER OVERLOADING DENTRO la classe)

  // "friend" gives this function(or operator) access to private data. è come se fosse una funzione esterna
  friend std::ostream& operator<<(std::ostream& os, const Point_c& p) {
    os << "Class. x = " << p.x << "; y = " << p.y << std::endl;
    return os;
  }
};   //;

// 
//THIS è un pointer all'oggetto su cui è invocata la member function. in automatico c++ dà implicitamente classebla::funzione(classebla* this)
//quindi tutte le member functions hanno un parametro in più, il THIS (NI)
// quindi <<  sta prendendo due args, piu il *this implicito. 

//Con FRIEND la funzione non è più MEMBER, ma diventa come una funzione esterna (e quindi NON SI BECCA PIÙ IL PARAMETRO IN PIÙ "this" DC)



int main() {
	  Point_s ps;
	  ps.x = 9.9;
	  ps.y = 3. / 7;
	  std::cout << ps;

	  Point_c pc;
	  // pc.x =7.6; // error
	  std::cout << pc;

	  Point_s* p = &ps;
	  p->x = 0.0;
	  std::cout << *p;  // operator overloading does not work with pointers

	  return 0;
}



//SIZE OF A CLASS IS >= sizes of member variables
