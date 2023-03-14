#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>  //std copy


enum class Insertion_method { push_back, push_front };

template <typename T>
class List {
 public:
  using value_type = T;
  std::size_t _size;

  // insert a new node with the value v according to the method m
  void insert(const value_type& v, const Insertion_method metodo){
    return metodo(v);
  }
  // return the size of the list
  std::size_t size() const {return _size; };

  // delete all the nodes of the list
  void reset();
 
  // constructor(s) for List
  List() = default;
  
  // copy semantics (deep copy)
  // move semantics
  ~List() = default;
  
 private:
  // private struct node with the proper value_type
  // why is a good idea nesting node?
  struct node {
    value_type value;
    std::unique_ptr<node> next;

    // implement suitable constructor(s) for node
    //node(value_type& val, std::unique_ptr<node> pross): value{val}, next{pross} {}
    node() = default;
    //node(const T& v, const std::unique_ptr<node>& pross) = delete;
    // copy and move semantics if needed

    ~node() = default; 
  };


  
  // append the newly created node at the end of the list
  void push_back(const value_type& v);
      
  
  // insert the newly created node in front of the list
  void push_front(const value_type& v){
    node nuovonodo{};
    nuovonodo.value = v;
    nuovonodo.next = std::move(head);
    head = &nuovonodo;
    _size++;
  }
    
  std::unique_ptr<node> head;

  //friend std::ostream& operator<<(std::ostream& os, const List& l);
};

int main(){
  return 0;
}
