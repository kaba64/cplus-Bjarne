#include <iostream>
#include <exception>
#include <cmath>
#include "./../utils/Window.h"
#include "./../utils/Graph.h" 

int main() {
  
  try{
    using namespace Graph_lib;
    const int x_orig = 300;
    const int y_orig = 300;
    const int xlength = 400;
    const int ylength = 400;
    const int x_scale = 20;
    const int y_scale = 20;
    const int xOffset = 100;
    const int yOffset = 100;
    Graph_lib::Window win {600,600,"Function graphs"};
    const int xmax{win.x_max()};
    const int ymax{win.y_max()};
    
    Axis x {Axis::x,Point{xOffset,y_orig},xlength, xlength/x_scale, "1 == 20"};
    x.set_color(Color::red);
    win.attach(x);

    Axis y {Axis::y,Point{x_orig,ymax-yOffset},ylength, ylength/y_scale, "1 == 20"};
    y.set_color(Color::red);
    win.attach(y);
    gui_main();
    
  }catch(const std::exception& e){
    std::cerr<<"Error : "<<e.what()<<"\n";
    return 1;
  }catch(...){
    std::cerr<<"Undefind error\n";
    return 2;
  }
  return 0;
}
