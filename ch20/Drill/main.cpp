#include <iostream>
#include "vector.h"
#include "list.h"

template<typename Iter1,typename Iter2> Iter2 copy(Iter1 first1, Iter1 last1,Iter2 first2) {
  if (first1 == last1)
    return first2;
  
  for (Iter1 p = first1; p != last1; ++p,++first2) {
    *first2=*p;
  }
  return first2;
}

template<typename Iter,typename T> void printFindResult(const Iter first,const Iter last,const Iter findOutput,const T value){
  if(findOutput!=last)
    std::cout<<"The value "<<value<<" is found at "<<findOutput-first<<"\n";
  else
    std::cout<<"The value "<<value<<" is no found\n";
}

int main(int argc,char** argv){

  constexpr int SIZE{10};
  int tenInt[SIZE] = {0,1,2,3,4,5,6,7,8,9};
  vector<int> tenVector({0,1,2,3,4,5,6,7,8,9});
  tenVector.print_vector("tenVector");
  list<int> tenList({0,1,2,3,4,5,6,7,8,9});
  tenList.display();
  
  int tenInt2[SIZE];
  for(size_t i =0;i<SIZE;++i)
    tenInt2[i]=tenInt[i];
  vector<int> tenVector2(tenVector);
  list<int> tenList2(tenList);
  std::cout<<"\nIncrement the values in the containers by 3\n\n";
  for(auto p=tenVector.begin();p!=tenVector.end();++p)
    *p=*p+3;
  for(auto p=tenList.begin();p!=tenList.end();++p)
    *p=*p+3;
  for(size_t i=0;i<SIZE;++i)
    tenInt[i]+=3;
  tenVector.print_vector("tenVector");
  tenList.display();
  std::cout<<"Test the copy algorithm by copying the vector<int> (tenVector) element in the list<int> (tenList2)\n\n";
  std::cout<<"Before the copy algorithm: tenList2 : ";
  tenList2.display();
  copy(tenVector.begin(),tenVector.end(),tenList2.begin());
  std::cout<<"After the copy algorithm: tenList2 : ";
  tenList2.display();
  std::cout<<"\nUse the STL find algorithm\n\n";
  printFindResult(tenVector.begin(),tenVector.end(),std::find(tenVector.begin(),tenVector.end(),4),4);
  printFindResult(tenVector.begin(),tenVector.end(),std::find(tenVector.begin(),tenVector.end(),27),27);
  
  return 0;
}
