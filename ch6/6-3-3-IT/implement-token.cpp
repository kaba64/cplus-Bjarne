#include <iostream>
#include <std_lib_facilities.h>

class Token{
public:
  Token(char k, double val=0)
    :kind{k}, value{val}{}
  char kind;
  double value;
};

auto main () -> int
{
  Token t1{'+'};
  Token t2{'8',3.14};
  //Token tt=t2;
  //if(tt.kind!=t2.kind) error("impossible!");
  //t1=t2;
  std::cout<<"t1 value = "<<t1.value<<"\t t2 value = "<<t2.value<<"\n";
}
