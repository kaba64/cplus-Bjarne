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
  
  vector<int> vectorTestHight;
  
  vectorTestHight.push_back(1);
  vectorTestHight.push_back(5);
  vectorTestHight.push_back(3);
  vectorTestHight.push_back(8);
  vectorTestHight.push_back(4);
  vectorTestHight.push_back(7);
  vectorTestHight.print_vector("vectorTestHight");
  std::cout<<"\nTest high algorithm for the vector container\n\n";
  vector<int>::iterator temp = high(vectorTestHight.begin(),vectorTestHight.end());
  std::cout<<"The highest value was : "<<*temp<<"\n";
  return 0;
}
