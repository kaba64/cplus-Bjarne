#include <iostream>

class B1{
public:
  B1(){std::cout<<"Constructor of B1\n";}
  virtual void vf()const{std::cout<<"B1::vf\n";}
  void f()const{std::cout<<"B1::f\n";}
  ~B1(){std::cout<<"Destructor of B1\n";}
};

class D1: public B1{
public:
  D1(){std::cout<<"Constructor of D1\n";}
  void vf()const override{std::cout<<"D1::vf\n";}
  ~D1(){std::cout<<"Destructor of D1\n";}
};

int main(int argc,char **argv){

  D1 d1;
  std::cout<<"A &B1 object is defined and initialized to a D1 object: \n";
  B1& b1{d1};
  b1.vf();
  b1.f();
  return 0;
}
