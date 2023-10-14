// The main code is copied from Bjarne c++ book
#include <iostream>

auto main() -> int
{
  std::string previous = " ";
  std::string current;
  int count{0};
  
  while (std::cin>>current) {
    if (previous == current){
      count+=1;
      std::cout << "repeated word: " << current << '\n';
    }
    previous = current;
  }
  std::cout<<"The number of the repetition is = "<<count<<"\n";
}
