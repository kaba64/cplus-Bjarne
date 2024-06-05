#include "list.h"

template<std::input_iterator Iter> Iter high(Iter first, Iter last) {
  
  if (first == last)
    return last;
  
  Iter high = first;
  for (Iter p = first; p != last; ++p) {
    if (*high < *p) {
      high = p;
    }
  }
  return high;
}

int main(int argc,char** argv){
  list<int> lst;
  lst.push_back(10);
  lst.push_back(20);
  lst.push_back(30);
  lst.push_back(5);
  std::cout << "The initial list : ";
  lst.display(); // Output: 10 <-> 20 <-> 30 <-> 5 <-> .end()
  std::cout<<"\nUse push.front() to add an element : \n\n";
  lst.push_front(1);
  std::cout << "The list after using push_front(1): "; 
  lst.display(); // Output: 1 <-> 10 <-> 20 <-> 30 <-> 5 <-> .end()
  list<int>::iterator p = high(lst.begin(),lst.end());
  std::cout<<"The highest value was : "<<*p<<"\n";
  list<int>::iterator Increment{lst.begin()};
  std::cout<<"*Increment : "<<*Increment<<"\t*(Increment+7) : "<<*(Increment+7)<<"\n";
  list<int>::iterator temp = lst.insert(lst.begin()+2,4);
  std::cout << "The list after using insert(lst.begin()+2,4): ";
  lst.display(); // Output: 1 <-> 10 <-> 20 <-> 4 <-> 30 <-> 5 <-> .end()
  std::cout<<"*temp = "<<*temp<<"\n";
  temp = lst.erase(lst.begin()+3);
  std::cout << "The list after using erase(lst.begin()+3): ";
  lst.display(); // Output: 1 <-> 10 <-> 20 <-> 30 <-> 5 <-> .end()
  std::cout<<"*temp = "<<*temp<<"\n";
  lst.pop_front();
  std::cout << "The list after using pop_front(): ";
  lst.display(); // Output: 10 <-> 20 <-> 30 <-> 5 <-> .end()
  lst.pop_back();
  std::cout << "The list after using pop_back(): ";
  lst.display(); // Output: 10 <-> 20 <-> 30 <-> .end()
  return 0;
}
