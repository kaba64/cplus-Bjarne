#include <iostream>
#include <std_lib_facilities.h>
#include <vector>

class Token{
public:
  char kind;
  double value;
};

Token get_token(){
  Token temp;
  //std::cout<<"Please enter a kind followed by a value for the Token :"<<"\n";
  std::cin>>temp.kind>>temp.value;
  return temp;
}

vector<Token> tok;

auto main () -> int
{
  double sum{0};
  while(cin){
    Token t = get_token();
    tok.push_back(t);
  }
  //std::cout<<"t kind = "<<tok[0].kind<<"\t t value = "<<tok[0].value<<"\n";
  //std::cout<<"t kind = "<<tok[1].kind<<"\t t value = "<<tok[1].value<<"\n";
  //std::cout<<"t kind = "<<tok[2].kind<<"\t t value = "<<tok[2].value<<"\n";
  for(unsigned int i =0;i<tok.size();++i){
    switch(tok[i].kind){
    case '*':
      sum += tok[i-1].value*tok[i+1].value;
      break;
    }
  }
  std::cout<<"Result = "<<sum<<"\n";
}
