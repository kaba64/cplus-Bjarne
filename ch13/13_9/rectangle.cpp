#include <iostream>
#include <exception>
#include "./../utils/Simple_window.h"
#include "./../utils/Graph.h" 

int main() {

  try{
    using namespace Graph_lib;
    Point x{100,100};
    Simple_window win{x,600,400,"closedPolyline"};
    
    /*13-9 : rectangle*/
    Rectangle rec00{Point{150,100},200,100};
    Rectangle rec01{Point{50,50},Point{250,150}};
    Rectangle rec10{Point{50,150},Point{250,250}};
    Rectangle rec11{Point{250,50},200,100};
    
    rec00.set_fill_color(Color::yellow);
    rec01.set_fill_color(Color::blue);
    rec10.set_fill_color(Color::red);
    rec11.set_fill_color(Color::green);
    win.attach(rec00);
    win.attach(rec01);
    win.attach(rec10);
    win.attach(rec11);
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
