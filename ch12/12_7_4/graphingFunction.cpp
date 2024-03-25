#include <iostream>
#include <exception>
#include "./../utils/Simple_window.h"
#include "./../utils/Graph.h"

int main(int argc,char **argv) {
  
  try{
    using namespace Graph_lib;          
    Point tl{100, 100};                 
    Simple_window win {tl, 600, 400, "Canvas"}; 

    Axis xa{Axis::x,Point{20,300},280,10,"x axis"};
    win.attach(xa);
    //win.set_label("Canvas #2");

    Axis ya{Axis::y,Point{20,300},280,10,"y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);

    Function sine {sin,0,100,Point{20,150},1000,50,50};
    win.attach(sine);
    
    win.set_label("Canvas #4");
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
