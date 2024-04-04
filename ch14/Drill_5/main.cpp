#include <iostream>

class B1{
public:
  B1(){std::cout<<"Constructor of B1\n";}
  virtual void pvf()const=0;
  virtual void vf()const{std::cout<<"B1::vf\n";}
  void f()const{std::cout<<"B1::f\n";}
  ~B1(){std::cout<<"Destructor of B1\n";}
};

class D1: public B1{
public:
  D1(){std::cout<<"Constructor of D1\n";}
  void pvf()const override{std::cout<<"D1::pvf\n";} // need to be defined
  void vf()const override{std::cout<<"D1::vf\n";}
  void f()const{std::cout<<"D1::f\n";}
  ~D1(){std::cout<<"Destructor of D1\n";}
};

int main(int argc,char **argv){

  /*
    B1 b1;
    std::cout<<"Display the member functions of B1 class : \n";
    b1.vf();
    b1.f();
  */
  std::cout<<"\nB1 is a abstract class so that it cannot be initialized : \n\n";
  D1 d1;
  std::cout<<"Display the member functions of D1 class : \n";
  d1.vf();
  d1.f();
  
  std::cout<<"A &B1 object is defined and initialized to a D1 object: \n";
  B1& b2{d1};
  b2.vf();
  b2.f();
  return 0;
}
