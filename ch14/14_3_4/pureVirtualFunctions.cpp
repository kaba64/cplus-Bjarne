#include <iostream>

class B{
public:
  virtual void f() =0;
  virtual void g()=0;
};

class D1: public B{
public:
  void f() override{std::cout<<"D1::f\n";};
  void g() override{std::cout<<"D1: g\n";};
};

class D2: public B{
public:
  void f() override{std::cout<<"D2::f\n";};
};

class D3: public D2{
public:
  void g() override{std::cout<<"D3::f\n";};
};

int main(int argc,char **argv){
  /* compile time error
    B b;
   */
  D1 d1;

  /* compile time error since D2 is still abstract
  D2 d2;
  */

  D3 d3;
  d3.f();
  d3.g();
  
  return 0;
}
