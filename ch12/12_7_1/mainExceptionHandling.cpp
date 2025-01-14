#include <iostream>
#include <exception>
#include "./../utils/Simple_window.h"  // get access to our window library
#include "./../utils/Graph.h"          // get access to our graphics library facilities

int main() {

  try{
    using namespace Graph_lib;          // our graphics facilities are in Graph_lib
    Point tl{100, 100};                 // to become top left corner of window
    Simple_window win {tl, 600, 400, "Canvas"};    // make a simple window
    Polygon poly;                                  // make a shape (a polygon)
    
    poly.add(Point{300, 200});                     // add a point
    poly.add(Point{350, 100});                     // add another point
    poly.add(Point{400, 200});                     // add a third point
    poly.set_color(Color::red);                    // adjust properties of poly
    
    win.attach(poly);                              // connect poly to the window
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
