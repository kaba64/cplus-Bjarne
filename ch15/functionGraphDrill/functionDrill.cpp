#include <iostream>
#include <exception>
#include <cmath>
#include "./../utils/Simple_window.h"
#include "./../utils/Graph.h" 

inline double one(double){return 1.0;}
inline double slope(double x){return x/2;}
inline double square(double x){return x*x;}
inline double sloping_cos(double x){return cos(x)+slope(x);}
int main() {
  
  try{
    using namespace Graph_lib;
    const int xmax = 600;
    const int ymax = 600;
    const int x_orig = 300;
    const int y_orig = 300;
    const Point orig {x_orig,y_orig};
    const int xlength = 400;
    const int ylength = 400;
    const int x_scale = 20;
    const int y_scale = 20;
    const int xOffset = 100;
    const int yOffset = 100;
    const int r_min = -10;
    const int r_max = 11;
    const int n_points = 400;
    
    Simple_window win {Point(100,100),xmax,ymax,"Function graphs"};
    win.wait_for_button();
    
    Axis x {Axis::x,Point{xOffset,y_orig},xlength, xlength/x_scale, "1 == 20"};
    x.set_color(Color::red);
    win.attach(x);
    win.wait_for_button();
    
    Axis y {Axis::y,Point{x_orig,ymax-yOffset},ylength, ylength/y_scale, "1 == 20"};
    y.set_color(Color::red);
    win.attach(y);
    win.wait_for_button();
    
    Function s {one,r_min,r_max,orig,n_points,x_scale,y_scale};
    win.attach(s);
    win.wait_for_button();
    
    Function s2 {slope,r_min,r_max,orig,n_points,x_scale,y_scale};
    win.attach(s2);
    win.wait_for_button();
    
    const int yplot{y_orig-static_cast<int>(slope(static_cast<double>(r_min)))*y_scale-20};
    Text ts2 {Point{xOffset,yplot},"x/2"};
    win.attach(ts2);
    win.wait_for_button();

    Function s3 {square,r_min,r_max,orig,n_points,x_scale,y_scale};
    win.attach(s3);
    win.wait_for_button();

    Function s4 {cos,r_min,r_max,orig,n_points,x_scale,y_scale};
    s4.set_color(Color::blue);
    win.attach(s4);
    win.wait_for_button();
    
    Function s5 {sloping_cos,r_min,r_max,orig,n_points,x_scale,y_scale};
    win.attach(s5);
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
