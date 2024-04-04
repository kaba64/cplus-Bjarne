#include <iostream>

class B1{
public:
  virtual void vf()const{std::cout<<"B1::vf\n";}
  void f()const{std::cout<<"B1::f\n";}
};

class D1: public B1{
public:
  void vf()const override{std::cout<<"D1::vf\n";}
};

int main(int argc,char **argv){

  D1 d1;
  std::cout<<"Display the member functions of D1 class : \n";
  d1.vf();
  d1.f();
  return 0;
}
