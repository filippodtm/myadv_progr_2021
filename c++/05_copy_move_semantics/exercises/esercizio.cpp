#include <memory>

//pushfront aggiunge un blocco all'inizio della catena, devo partire dalla fine con un puntatore tmp e poi andare avanti fin quando becco un blocco che ha in head un nullpointer(?)
// tmp->next mi fa accedere al pointer del primo vagone



enum class method {push_back, push_front}

//
template <typename T>
class List{
public:

  
  void insert(const T& x, method m){ _insert(x,m); }
  void insert(T&& x, method m){_insert(std::move(x), m); }

  List()= default;         //ctor
  List(List&&) =default;
  List& operator= (List&&) = default;
  




private:
  template <typename X>
  void _insert(X&& x, method m){ //forwarding reference (not an r-value): can accept both rval and lval
    _insert(x,m);
  }


int main(){
  
