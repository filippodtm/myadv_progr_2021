#include <array>
#include <iostream>
#include <vector>

//struct makes all symbols public (we can write private: ..)
struct Point_s {
  double x;
  double y;
  void print();
};   //;

void Point_s::print() {
  std::cout << "Structure; x = " << x << "; y = " << y << std::endl;
}


void Print(Point_s p){
  std::cout << "Structure; x = " << p.x << "; y = " << p.y << std::endl;
}

///Class contains member variables, member functions[METHODS]. Not public
class Point_c { 
  double x;
  double y;
 public:
  void print() {
    std::cout << "Class; x = " << x << "; y = " << y << std::endl;
  } 
};   // ; at the end
//INTERPHACE(?): set of all public elements of the class




int main() {
  Point_s ps;
  ps.x = 9.9;
  ps.y = 3. / 7;
  Print(ps);  //se scritta dentro, ps.print come metodo. Scrivo Print(ps) se scritta fuori (?)
  

  Point_c pc;
  // pc.x =7.6; // error
  pc.print();  // can access private data through public functions


  Point_s* p = &ps;   //pointers di tipo point_s 
  p->x = 0.0;  // x è attributo di ps, a cui punta p
               //importante sta roba quando fa "this"(DC!)
  p->print();

  auto& pr = ps;
  ++ pr.x;    
  pr.print();

  Point_s array_of_structs[8];  // built-in array
  array_of_structs[0].x = 1;
  array_of_structs[0].y = 2;

  std::array<Point_s, 5> as;   //std array
  as[3].x = 3;

  std::vector<Point_s> vs;     //std vector
  vs.push_back(ps);
  vs[0].x = 999;
  ps.x = 11;      //vs0 e ps non sono collegati
  ps.print();
  vs[0].print();

  return 0;
}


