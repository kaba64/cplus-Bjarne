#include <iostream>
#include <exception>
#include "./../utils/Simple_window.h"
#include "./../utils/Graph.h" 

int main() {

  try{
    using namespace Graph_lib;

    Point x{100,100};
    Simple_window win1{x,600,400,"two lines"};

    Line horizental{x,Point{200,100}};
    Line vertical{Point{150,50},Point{150,150}};
    win1.attach(horizental);
    win1.attach(vertical);

    win1.wait_for_button();
    
  }catch(const std::exception& e){
    std::cerr<<"Error : "<<e.what()<<"\n";
    return 1;
  }catch(...){
    std::cerr<<"Undefind error\n";
    return 2;
  }
  return 0;
}
