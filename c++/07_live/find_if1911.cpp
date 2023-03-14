#include <vector>


template <typename I, typename T>
//I is random access iterator
I find(I first, I last, T value){
  if (first ==last) return last;
  
  //  --last;
  //auto tmp= std::move(*last);
  //if(tmp==value) return last;
  //*last = value;
  
  //while(*first != value) ++first;

  //+last = std::move(tmp);
  //if (first==last) return ++last;
  
  //return first;

  
   while(first != last && *first != value) ++first;  //trivial version
   return first;
}



int main(){
  std::vector<int> v;
  for (auto i=0; i<100001; ++i)
    v.emplace_back(i);

  auto x = find(v.begin(), v.end(), 100000);
  if(x==v.end())
    std::cout << "not found" <<std::endl;
  else
    std::cout << "found" << *x <<std::endl;
  

}
