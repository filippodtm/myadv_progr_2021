#include <iostream>
#include <vector>
#include <memory>
#include <iterator>

/* A pool of blazingly fast stacks */
/* STUDENTS: Erica De Toni, Filippo Di Tommaso */

template <typename T, typename N = std::size_t>
class stack_pool{ 
  struct node_t{
    T value;
    N next;
  };

  /* La stackpool mantiene ogni nodo in un std::vector. L'indirizzo di un nodo è 
   * uguale a 1 + (index in cui è situato il nodo nel vettore). */ 
  std::vector<node_t> pool;
  
  // Type degli indici delle stacks. Ogni pila è identificata dall'indice del suo primo nodo.
  using stack_type = N;
  
  using value_type = T;
  using size_type = typename std::vector<node_t>::size_type;  
  stack_type free_nodes{0};    // empty at the beginning

  /* dà in return il nodo in posizione x nel vettore pool (senza bounds checking) */
  node_t& node(stack_type x) noexcept { return pool[x-1]; }              
  const node_t& node(stack_type x) const noexcept { return pool[x-1]; }

  
public:
  /* Default ctor per stack_pool */
  stack_pool() noexcept = default;
  /* Custom ctor per stack_pool. Usa std::vector::reserve(n)  */
  explicit stack_pool(size_type n) : pool{}  {pool.reserve(n); } 
  

 
  template <typename S >
  class Iterator { 
  /* Classe Iterator per iterare attraverso una pila. Ha come attributi un indice
   * current e un puntatore ptr ad un oggetto di tipo stack_pool.
   * Il template S si riferirà a T o const T  */
    stack_pool* ptr;
    N current;
    public:
    using value_type = S ;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag ; 
    using reference = value_type&;
    using pointer = value_type*;

    Iterator(stack_pool* p , N c) : ptr{p}, current{c} {}

    reference operator*(){ return ptr->value(current); }
    pointer operator->(){ return &**this ; }

    /* Pre-increment */
    Iterator& operator++(){
      current = ptr->next(current) ;
      return *this;  
    }
    /* Post increment */
    Iterator operator++(int){
      auto tmp = *this;
      ++current;
      return tmp;
    }
    friend bool operator==( const Iterator& a, const Iterator& b) {return a.current==b.current;}  
    friend bool operator!=( const Iterator& a, const Iterator& b) {return !(a==b);}
  };
  

  
  using iterator = Iterator<T>;
  using const_iterator = Iterator<const T>;

  iterator begin(stack_type x) {return iterator{this, x};}
  iterator end(stack_type ){return iterator{this, stack_type(0)};}

  const_iterator begin(stack_type x) const {return const_iterator{this, x};}
  const_iterator end(stack_type ) const {return const_iterator{this, stack_type(0)};}
  
  const_iterator cbegin(stack_type x) const {return const_iterator{this, x};}
  const_iterator cend(stack_type ) const {return const_iterator{this,stack_type(0) };}


  // Dà una stack vuota.
  stack_type new_stack() noexcept {return stack_type(0);}    
  // Riserva n nodi con std::vector::reserve
  void reserve(size_type n) {pool.reserve(n); }  
  // Dà in return la capacity di pool come std::vector
  size_type capacity() const noexcept {return pool.capacity(); } 

  bool empty(stack_type x) const noexcept {
    if (x == end())
       return true;
    else
       return false;
  }
  stack_type end() const noexcept { return stack_type(0); }       

  T& value(stack_type x) noexcept {return node(x).value; }    //ok
  const T& value(stack_type x) const noexcept {return node(x).value; }      //ok

  stack_type& next(stack_type x) noexcept {return node(x).next; }   //ok
  const stack_type& next(stack_type x) const noexcept {return node(x).next; }      //ok


  stack_type push(const T& val, stack_type l){
    if( empty(free_nodes) ){  //non ci sono free_nodes disponibili
      pool.push_back(node_t{val, l});    
      return static_cast<N>(pool.size()) ;   
    }
    //se ci sono freenodes
    auto tmp = free_nodes;
    value(free_nodes) = val;
    free_nodes = next(free_nodes);
    next(tmp) = l;
    return tmp;
  }
  stack_type push(T&& val, stack_type l){
    if( empty(free_nodes) ){  //non ci sono free_nodes disponibili
      pool.push_back(node_t{ std::move(val), l});    
      return static_cast<N>(pool.size()) ;   
    }
    //se ci sono freenodes
    auto tmp = free_nodes;
    value(free_nodes) = std::move(val);
    free_nodes = next(free_nodes);
    next(tmp) = l;
    return tmp;
  }

  /* Rimuove il primo nodo della pila x e lo aggiunge alla pila dei freenodes */
  stack_type pop(stack_type x){
    auto tmp = next(x);     
    next(x) = free_nodes;      // il nodo x punta al primo freenode
    free_nodes = x;            //sposto la testa dei freenodes in x
    return tmp;
  }
  
  /* libera l'intera pila iterando pop ad ogni nodo */
  stack_type free_stack(stack_type x){
    while( x ){
      x = pop(x);
    }
    return x;
  }
};

