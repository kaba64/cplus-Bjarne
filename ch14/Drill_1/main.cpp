#include <iostream>

class B1{
public:
  virtual void vf()const{std::cout<<"B1::vf\n";}
  void f()const{std::cout<<"B1::f\n";}
};

int main(int argc,char **argv){

  B1 b1;
  std::cout<<"Display the member functions of B1 class : \n";
  b1.vf();
  b1.f();
  return 0;
}
