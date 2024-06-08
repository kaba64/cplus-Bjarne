#include <iostream>
#include "vector.h"

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
  
  vector<int> vectorErase;
  
  vectorErase.push_back(1);
  vectorErase.push_back(5);
  vectorErase.push_back(3);
  vectorErase.push_back(8);
  vectorErase.push_back(4);
  vectorErase.push_back(7);
  vectorErase.print_vector("vectorErase");
  std::cout<<"\nTest erase() with p = begin()+2 :\n\n";
  vectorErase.erase(vectorErase.begin()+2);
  vectorErase.print_vector("vectorErase");
  std::cout<<"\nTest insert() with p = begin()+3 :\n\n";
  vectorErase.insert(vectorErase.begin()+3,5);
  vectorErase.insert(vectorErase.begin()+3,6);
  vectorErase.print_vector("vectorErase");
  return 0;
}
