#include <iostream>
#include <string>

class vector{
public:
  vector(size_t s,int count=0):sz{s},elem{new double[s]}{
    for(size_t i=0;i<s;++i){
      elem[i]=count;
      ++count;
    }
  }
  ~vector(){delete[] elem;}
  size_t size() const{return sz;}
  double get(size_t i) const{return elem[i];}
  void set(size_t n,double v){elem[n]=v;}
  void print_vector()const;
private:
  size_t sz;
  double* elem;
};

void vector::print_vector()const{
  std::string name = "vector"+std::to_string(sz);
  for(size_t i=0;i<sz;++i){
    std::cout<<name<<"["<<i<<"] = "<<elem[i]<<"\t";
    if(i==sz-1 || (i+1)%3==0)
      std::cout<<"\n";
  }
}

void print_array(std::ostream& os,const int* a,const size_t size,const std::string name){
  for(size_t i=0;i<size;++i){
    os<<name<<"["<<i<<"] = "<<a[i]<<"\t";
    if(i==size-1 || (i+1)%3==0)
      os<<"\n";
  }
}

void printPointer(std::ostream& os,const int* a,const size_t size,const std::string name){
  for(size_t i=0;i<size;++i){
    os<<name<<"+"<<i<<" = "<<reinterpret_cast<uintptr_t>(a+i)<<"\t";
    if(i==size-1 || (i+1)%3==0)
      os<<"\n";
  }
}

int main(int argc,char** argv){

  int* oneInt = new int{7};
  int* p1 = oneInt;

  std::cout<<"p1 = "<<reinterpret_cast<uintptr_t>(p1)<<"\t *p1 = "<<*p1<<"\n";

  size_t size2{7};
  int* p2 = new int[size2];
  p2[0]=1;
  for(size_t i=1;i<size2;++i)
    p2[i] = 2*p2[i-1];
  
  print_array(std::cout,p2,size2,"p2");
  printPointer(std::cout,p2,size2,"p2");

  int* p3 = p2;

  p2=p1;
  p2=p3;
  std::cout<<"\nThe values of p1 and p2 and of what they point to\n\n";
  print_array(std::cout,p1,1,"p1");
  printPointer(std::cout,p1,1,"p1");
  print_array(std::cout,p2,size2,"p2");
  printPointer(std::cout,p2,size2,"p2");
  
  delete oneInt;
  delete[] p2;

  size_t size3{10};
  p1 = new int[size3];
  p1[0]=1;
  for(size_t i=1;i<size3;++i)
    p1[i] = 2*p1[i-1];

  p2 = new int[size3];

  delete[] p1;
  delete[] p2;
  
  vector vector1(size3);
  vector1.set(0,1);
  for(size_t i=1;i<size3;++i)
    vector1.set(i,2*vector1.get(i-1));
  
  vector vector2(size3);
  
  return 0;
}
