#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include <typeinfo>

template<typename T> T str_to_object_T(const std::string & s){

  std::istringstream is{s};
  T input;
  is>>input;
  if(!is){
    std::string type {typeid(T).name()};
    throw std::runtime_error("Error : The format of "+s+" is not "+type);
  }
  return input;
}

int main(int argc,char **argv){

  double d1 = str_to_object_T<double>("1.25");
  std::cout<<"d1 = "<<d1<<"\n";
  double d2 = str_to_object_T<double>("twelve point three");
  std::cout<<"d2 = "<<d2<<"\n";
  return 0;
}
