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

class D2: public D1{
public:
  D2(){std::cout<<"Constructor of D2\n";}
  void pvf()const override{std::cout<<"D2::pvf\n";}
  ~D2(){std::cout<<"Destructor of D2\n";}
};


int main(int argc,char **argv){
  
  D2 d2;
  std::cout<<"Display the member functions of object instaance of D2 class : \n";
  d2.pvf();
  d2.vf();
  d2.f();
  
  return 0;
}
