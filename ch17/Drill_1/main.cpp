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

void initArray(int* a,const size_t size){
  size_t count{100};
  for(size_t i=0;i<size;++i){
    a[i]=count;
    ++count;
  }
}

int main(int argc,char** argv){

  const size_t size1{10};
  int* tenInt = new int[size1];
  initArray(tenInt,size1);
  print_array(std::cout,tenInt,size1,"tenInt");
  
  const size_t size2{20};
  int* twentyInt = new int[size2];
  initArray(twentyInt,size2);
  print_array(std::cout,twentyInt,size2,"twentyInt");
  delete[] tenInt;
  delete[] twentyInt;
  std::cout<<"\nvector : \n\n";
  vector vector10(10,100);
  vector vector20(20,100);
  vector10.print_vector();
  vector20.print_vector();
  
  return 0;
}
