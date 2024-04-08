#include <iostream>
#include <exception>
#include <cmath>
#include "./../utils/Simple_window.h"
#include "./../utils/Graph.h" 

inline double one(double){return 1.0;}
inline double slope(double x){return x/2;}
inline double square(double x){return x*x;}

int main() {
  
  try{
    using namespace Graph_lib;

    const int xmax = 600;
    const int ymax = 400;
    const int x_orig = xmax/2;        // position of (0,0) is center of window
    const int y_orig = ymax/2;
    const Point orig {x_orig,y_orig};
    const int r_min = -10;            // range [–10:11)
    const int r_max = 11;
    const int n_points = 400;        // number of points used in range
    const int x_scale = 30;          // scaling factors
    const int y_scale = 30;
    const int xlength = xmax-40; // make the axis a bit smaller than the window
    const int ylength = ymax-40;
    
    Simple_window win {Point{100,100},xmax,ymax,"Function graphing"};
    win.wait_for_button();

    Axis x {Axis::x,Point{20,y_orig},xlength, xlength/x_scale, "one notch == 1"};
    x.set_color(Color::red);
    x.label.move(-160,0);
    x.notches.set_color(Color::dark_red);
    win.attach(x);
    win.wait_for_button();
    
    Axis y {Axis::y,Point{x_orig,ylength+20},ylength, ylength/y_scale, "one notch == 1"};
    y.set_color(Color::red);
    win.attach(y);
    win.wait_for_button();
    
    Function s {one,r_min,r_max,orig,n_points,x_scale,y_scale};
    win.attach(s);
    win.wait_for_button();

    Text ts {Point{100,y_orig-40},"one"};
    win.attach(ts);
    win.wait_for_button();
    
    Function s2 {slope,r_min,r_max,orig,n_points,x_scale,y_scale};
    win.attach(s2);
    win.wait_for_button();

    Text ts2 {Point{100,y_orig+y_orig/2-20},"x/2"};
    win.attach(ts2);
    win.wait_for_button();
    
    Function s3 {square,r_min,r_max,orig,n_points,x_scale,y_scale};
    win.attach(s3);
    win.wait_for_button();

    Text ts3 {Point{x_orig-100,20},"x*x"};
    win.attach(ts3);
    win.wait_for_button();

    Function s4 {log,0.000001,r_max,orig,200,30,30};
    win.attach(s4);
    win.wait_for_button();
    
    Function s5 {sin,r_min,r_max,orig,200,30,30};
    s5.set_color(Color::blue);
    win.attach(s5);
    win.wait_for_button();

    Function s6 {cos,r_min,r_max,orig,200,30,30};
    win.attach(s6);
    win.wait_for_button();

    // using Lambda expression
    Function s7 {[](double x){return cos(x)+slope(x);},r_min,r_max,orig,400,30,30};
    s7.set_color(Color::green);
    win.attach(s7);
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
