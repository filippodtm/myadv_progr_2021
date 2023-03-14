#include <iostream>

//Non-scoped (ie:senza CLASS) non funziona, si confonde con la funzione decimal(qualcosa)
//ocio però: se uso scopedenum non li converte automaticamente in int per l'output
enum class month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

using namespace std;

int main() {
  cout << static_cast<int>(month::nov) << endl;
  cout << static_cast<int>(month::dec) << endl;

  return 0;
}


//oppure meglio  using std::cout; using std::endl;
// senza scrivere "using namespace std"
