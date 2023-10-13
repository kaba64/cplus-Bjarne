#include <iostream>
#include <math.h>
auto main() -> int
{
  int num;
  std::cout<<"Please enter an integer:\n";
  std::cin>>num;
  
  std::cout<<"n = "<<num
	   <<"\nn+1 == "<<num+1
	   <<"\nthree times n == "<<num*3
	   <<"\ntwise n == "<<num+num
	   <<"\nn squared == "<<num*num
	   <<"\nhaf of n == "<<num/2
	   <<"\nsquare root of n == "<<sqrt((double)num)
	   <<"\n";
}
