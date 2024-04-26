#include <iostream>

constexpr size_t size = 10;
int ga[size] = {1,2,4,8,16,32,64,128,256,512};

void printVector(const int* p, const size_t sizeIn, const std::string& name){
  for(size_t i=0;i<sizeIn;++i){
    std::cout<<name<<"["<<i<<"] = "<<p[i]<<"\t";
    if(i==sizeIn-1 || (i+1)%3==0)
      std::cout<<"\n";
  }
}

void f(int a[],const size_t sizeIn){

  int la[size];
  for(size_t i=0;i<sizeIn;++i)
    la[i]=a[i];

  printVector(la,sizeIn,"la");
  
  int* p = new int[sizeIn];
  for(size_t i=0;i<sizeIn;++i)
    p[i]=la[i];
  printVector(p,sizeIn,"p");
  
  delete[] p;
}

int main(int argc,char** argv){
  
  std::cout<<"\nf(ga,size)\n\n";
  f(ga,size);
  
  int aa[size];  
  for(size_t i=0;i<size;++i){
    if(i==0)
      aa[i]=1;
    else
      aa[i]=aa[i-1]*(i+1);
  }
  std::cout<<"\nf(aa,size)\n\n";
  f(aa,size);
  
  return 0;
}
