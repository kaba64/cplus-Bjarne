//#include <iostream>
#include <exception>
#include "./../utils/Simple_window.h"
#include "./../utils/Graph.h"          
#include "./../utils/std_lib_facilities.h"

int main() {

  try{
    using namespace Graph_lib;
    Point tl{100, 100};
    Simple_window win {tl, 600, 400, "My window"};

    /*12-7-3 section*/
    Axis xa{Axis::x,Point{20,300},280,10,"x axis"};
    win.attach(xa);
    Axis ya{Axis::y,Point{20,300},280,10,"y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);
    
    /*12-7-4 section*/
    Function sine {sin,0,100,Point{20,150},1000,50,50};
    sine.set_color(Color::blue);
    win.attach(sine);

    /*12-7-5 section*/
    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});
    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);

    /*12-7-6 section*/
    Rectangle r {Point{200,200}, 100, 50};
    win.attach(r);
    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{200,100});
    poly_rect.add(Point{100,100});
    poly_rect.add(Point{50,75});
    win.attach(poly_rect);

    /*12-7-7 section*/
    r.set_fill_color(Color::yellow);
    poly.set_style(Line_style(Line_style::dash,4));
    poly_rect.set_style(Line_style(Line_style::dash,2));
    poly_rect.set_fill_color(Color::green);

    /*12-7-8 section*/
    Text t {Point{150,150}, "Hello, graphical world!"};
    t.set_font(Graph_lib::Font::times_bold);
    t.set_font_size(20);
    win.attach(t);

    /*12-7-8 section*/
    Circle c {Point{100,200},50};
    Ellipse e {Point{100,200}, 75,25};
    e.set_color(Color::dark_red);
    Mark m {Point{100,200},'x'};
    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes {Point{100,20},oss.str()};
    win.attach(c);
    win.attach(m);
    win.attach(e);
    win.attach(sizes);
    
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
