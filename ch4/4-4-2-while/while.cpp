#include <iostream>

auto main() -> int
{
  char ch='a';
  int num = ch;
  while(num<='z'){
    std::cout<<ch<<"\t"<<num<<"\n";
    ch = char(ch+1);
    ++num;
  }
}
