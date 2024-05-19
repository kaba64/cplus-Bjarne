#include <iostream>

void copy(int* f1,int* e1,int* f2){
  for(int* it=f1;it!=e1;++it,++f2)
    *f2=*it;
}

template<typename T> void printArray(const T* f1,const T* e1,const std::string name){
  size_t count{0};
  for(auto it=f1;it!=e1;++it){
    std::cout<<name<<"["<<count<<"] = "<<*it<<"\t";
    if((count+1)%3==0 && it!=(e1-1))
      std::cout<<"\n";
    ++count;
  }
  std::cout<<"\n";
}

int main(int argc,char** argv){
  const int size = 10;
  int a[size]={0,1,2,3,4,5,6,7,8,9};
  printArray(&a[0],&a[0]+size,"a");
  int b[size];
  copy(&a[0],&a[0]+size,&b[0]);
  printArray(&b[0],&b[0]+size,"b");
  return 0;
}
