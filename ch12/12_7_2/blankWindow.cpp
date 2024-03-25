#include <iostream>
#include <exception>
#include "./../utils/Simple_window.h"  // get access to our window library

int main(int argc,char **argv) {
  
  try{
    using namespace Graph_lib;          
    Point tl{100, 100};                 // to become top left corner of window
    Simple_window win {tl, 600, 400, "Canvas"};    // make a simple window
    
    win.wait_for_button();                         // give control to the display engine
  }catch(const std::exception& e){
    std::cerr<<"Error : "<<e.what()<<"\n";
    return 1;
  }catch(...){
    std::cerr<<"Undefind error\n";
    return 2;
  }
  return 0;
}
