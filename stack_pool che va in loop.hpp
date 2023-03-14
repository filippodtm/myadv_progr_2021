#include <iostream>
#include <vector>
#include <memory>
//#include <utility>
#include <iterator>


template <typename T, typename N = std::size_t>
class stack_pool{    //è la classe che ha vari membri scritti sotto  
  struct node_t{
    T value;
    N next;
    //node_t() = default;  //?   dobbiamo metterci  il custom anche?
  }; //fine struct 
  
  std::vector<node_t> pool;   //pool è il nome del vettore e all'inizio è vuoto
  using stack_type = N;       //type delle l
  using value_type = T;
  using size_type = typename std::vector<node_t>::size_type;    //dimensione del vettore in sostanza 
  stack_type free_nodes{0}; // at the beginning, it is empty (forse =0;)

  node_t& node(stack_type x) noexcept { return pool[x-1]; }              
  const node_t& node(stack_type x) const noexcept { return pool[x-1]; }

  public:
  stack_pool() = default;
  explicit stack_pool(size_type n): pool{ std::vector<node_t>{} }  {
    pool.reserve(n);
  }  // reserve n nodes in the pool 
  

//iteratori ////////////////////////////////////////////////////////////////////////////
  template <typename S  = std::size_t>
  class Iterator { 
    stack_pool* ptr;
    node_t* current;
    public:
    using value_type = S ;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag ; 
    using reference = value_type&;
    using pointer = value_type*;

    Iterator(stack_pool* p ,node_t* c) : ptr{p}, current{c} {}

    reference operator*(){ return current->value; }   //copia
    pointer operator->(){ return &**this ; }  //copy
    Iterator& operator++(){               // dep on how memory is stored
      auto a = current->next;
      current = &(ptr->node(a)) ;
      return *this;
    }
  Iterator operator++(int){      //post increment 
      auto tmp = *this;
      ++current ;
      return tmp;
  }
  friend bool operator==( const Iterator& a, const Iterator& b) {return a.current==b.current;}  
  friend bool operator!=( const Iterator& a, const Iterator& b) {return !(a==b);}
  };
//fine iteratori/////////////////////////////////////////////////////////////////////////
  
  
  using iterator = Iterator<T>;
  using const_iterator = Iterator<const T>;

  iterator begin(stack_type x){return iterator{ this, &node(x)};}
  iterator end(stack_type ){return iterator{ this, nullptr};}


  const_iterator begin(stack_type x) const {return const_iterator{this, &node(x)};}
  const_iterator end(stack_type ) const {return const_iterator{this, nullptr};}
  
  const_iterator cbegin(stack_type x) const {return const_iterator{this, &node(x)};}
  const_iterator cend(stack_type ) const {return const_iterator{this, nullptr};}
    
  stack_type new_stack() {return stack_type(0);}            // return an empty stack

  void reserve(size_type n){ pool.reserve(n); }  // reserve n nodes in the pool
  size_type capacity() const {return pool.capacity(); } //forse capacity() // the capacity of the pool

  bool empty(stack_type x) const {
    if (x == end())
       return true;
    else
       return false;
  }

  stack_type end() const noexcept { return stack_type(0); }       

  T& value(stack_type x) {return node(x).value; }    //ok
  const T& value(stack_type x) const {return node(x).value; }      //ok

  stack_type& next(stack_type x) {return node(x).next; }   //ok
  const stack_type& next(stack_type x) const {return node(x).next; }      //ok


  stack_type push(const T& val, stack_type l){
    if( free_nodes > end() ) {
      auto tmp = free_nodes;
      value(free_nodes) = val;
      free_nodes = next(free_nodes);
      next(tmp) = l;
      l = tmp;
    }
    else{  //non ci sono free_nodes disponibili
      pool.push_back( node_t{val, l} );     //costruisco il nodo e la dimensione si upgrada in automatico
      l = pool.size ;                       //si gestisce da solo std::vector
    }
    return l;
  }
  stack_type push(T&& val, stack_type l){
    if( free_nodes > end()) {
      auto tmp = free_nodes;
      value(free_nodes) = val;
      free_nodes = next(free_nodes);
      next(tmp) = l;
      l = tmp;
    }
    else{   //non ci sono free_nodes disponibili
      pool.push_back( node_t{val, l} );     //costruisco il nodo e la dimensione si upgrada in automatico
      l = pool.size();                     //si gestisce std::vector
    }
    return l;
  }

  stack_type pop(stack_type x){
    auto tmp = next(x);
    next(x) = free_nodes;      //aggiungo node(x) ai free nodes:
    free_nodes = x;
    return tmp;
  }

  stack_type free_stack(stack_type x){
    while(x != end() ){
      x = pop(x);
    }
    return x;
  }
};

