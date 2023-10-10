#include <iostream>
#include <exception>
#include <limits>

auto main() -> int
{
  try{
    int x{0};
    std::cout<<"Please enter an integer variable : "<<"\n";
    std::cin>>x;
    //if(!std::cin) return 5;
    std::cout<<"Input integer is = "<<x<<"\n";
  }catch(std::runtime_error& e){
    std::cerr<<"Runtime error: "<<e.what()<<"\n";
    return 1;
  }catch(...){
    std::cerr<<"Exception : something went wrong!\n";
    return 2;
  }
}
