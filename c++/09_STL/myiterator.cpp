#include<iterator>
...
template <typename T>
class List<T>::Iterator {
  typename List<T>::node* current;
  public:
  using value_type = T ;
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::forward_iterator_tag ;
  using reference = value_type&;
  using pointer = value_type*;

  reference operator*(){
    return current->value; }   //copy
  pointer operator->() { return &**this ; }  //copy
  Iterator& operator++(){      //no copy, dep on how memory is stored
    current = advance(current) ;
    return *this;
  }
  friend bool operator==( const Iterator&, const Iterator&) ;
  //return a.current==b.current;  
  friend bool operator!=( const Iterator&, const Iterator&) ;
  // return !(a==b);
};
 
