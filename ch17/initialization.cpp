#include <iostream>

class X{
  int x1, x2;
  double y1;
public:
  X(int x1in, int x2in, double y1in)
    :x1{x1in}, x2{x2in}, y1{y1in}{}
  void print()const
  {
    std::cout<<"x1 = "<<x1<<"\n";
    std::cout<<"x2 = "<<x2<<"\n";
    std::cout<<"y1 = "<<y1<<"\n";
  }
};

auto main() -> int
{
  double* p4 = new double[5] {0.,1.,2.,3.,4.};
  //X* p5 = new X{1,2,5.5};
  //p5->print();
  double* ptr=nullptr;
  if(ptr){ //equivalent to ptr!=nullptr
    std::cout<<"Not initialized!"<<std::endl;
  }else{
    std::cout<<"p4[3] = "<<p4[3]<<std::endl;
    std::cout<<ptr<<std::endl;
  }
}
