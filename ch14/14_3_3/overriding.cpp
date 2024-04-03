#include <iostream>

class B{
public:
  virtual void f() const{std::cout<<"B::f\n";}
  void g()const{std::cout<<"B::g\n";}
};

class D: public B{
public:
  void f() const override{std::cout<<"D::f\n";}
  void g(){std::cout<<"D::g\n";}
};

class DD: public D{
public:
  void f(){std::cout<<"DD::f\n";}
  void g() const{std::cout<<"DD::g\n";}
};

void call(const B& b){
  b.f();
  b.g();
}

int main(int argc,char **argv){
  B b;
  D d;
  DD dd;
  std::cout<<"passing B to call() : \n";
  call(b);
  std::cout<<"passing D to call() : \n";
  call(d);
  std::cout<<"passing DD to call() : \n";
  call(dd);

  std::cout<<"Calling member functions of B from main : \n";
  b.f();
  b.g();

  std::cout<<"Calling member functions of D from main : \n";
  d.f();
  d.g();

  std::cout<<"Calling member functions of DD from main : \n";
  dd.f();
  dd.g();
  
  return 0;
}
