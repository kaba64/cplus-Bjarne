#include <iostream>
/*Try this of 3-9-2 unsafe conversions page 81
  Kazem Bzesefidpar
  October 15 2023*/

int main(int argc, char* argv[]){
  double d{0};
  while(std::cin>>d){   // The below statements will be repeated as long as here is input
    int i{d};           // try to squeeze a double into an int 
    char c{i};          // try to squeeze an int into a char
    int i2{c};          // get the integer value of the character
    std::cout<<"d = "<<d<<", i = "<<i<<", i2 = "<<i2<<", char = "<<c<<"\n";
  }
  return 0;
}
