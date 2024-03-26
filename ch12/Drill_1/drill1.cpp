#include <iostream>
#include <exception>
#include "./../utils/Simple_window.h"
#include "./../utils/Graph.h"          

int main() {

  try{
    using namespace Graph_lib;
    Point tl{100, 100};
    Simple_window win {tl, 600, 400, "My window"};
    
    win.wait_for_button();
  }catch(const std::exception& e){
    std::cerr<<"Error : "<<e.what()<<"\n";
    return 1;
  }catch(...){
    std::cerr<<"Undefind error\n";
    return 2;
  }
  return 0;
}
