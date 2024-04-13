#include <iostream>

class X{
public:
  X(int x1in, int x2in, double y1in)
    :x1{x1in}, x2{x2in}, y1{y1in}{}
  void print()const;
private:
  int x1, x2;
  double y1;
};

void X::print()const{
  std::cout<<"x1 = "<<x1<<"\n";
  std::cout<<"x2 = "<<x2<<"\n";
  std::cout<<"y1 = "<<y1<<"\n";
}

int main(int argc,char **argv){
  
  double* p4 = new double[5] {0.,1.,2.,3.,4.};

  X* p5 = new X{1,2,5.5};
  p5->print();

  std::cout<<"\nTest the initialization of the poiner to nullptr\n\n";
  double* ptr=nullptr;
  if(ptr){ //equivalent to ptr!=nullptr
    std::cout<<"Not initialized!"<<std::endl;
  }else{
    std::cout<<"p4[3] = "<<p4[3]<<std::endl;
    std::cout<<ptr<<std::endl;
  }
  return 0;
}
