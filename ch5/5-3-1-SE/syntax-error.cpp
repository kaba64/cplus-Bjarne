#include <iostream>

int area(int,int);

auto main() -> int
{
  //Int a = area(7,1);
  //int a = area("seven",8);
  //int a = area(7.88,8.66); //My compiler did not give error or warning for this
  char a = area(100,9999); // My compiler did not give error or warning for this
  std::cout<<a<<"\n";
}

int area(int lenght,int height)
{
  return lenght*height;
}
