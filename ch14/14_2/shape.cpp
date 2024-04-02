/*The classes' definitions are token from the codes (provided) 
  and book : Programming: Principles and Practice Using C++ Second Edition*/

#include <iostream>
#include <FL/Fl.H> /*header includes the core FLTK library*/
#include <FL/Fl_Window.H> /*header includes the definition of the Fl_Window class, which represents a window in FLTK*/
#include <FL/fl_draw.H> /*header includes drawing functions and utilities for FLTK*/
#include <vector>
#include <initializer_list>
#include <exception>


/*1 : Point*/
struct Point {
  int x,y;
  Point(int xx, int yy) : x(xx), y(yy) { }
  Point() :x(0), y(0) { }
  Point& operator+=(Point d) { x+=d.x; y+=d.y; return *this; }
};

inline bool operator==(Point a, Point b) { return a.x==b.x && a.y==b.y; }

inline bool operator!=(Point a, Point b) { return !(a==b); }

/*2 : Line_style */
struct Line_style {
  enum Line_style_type {
			solid=FL_SOLID,           // ------- 
			dash=FL_DASH,             // - - - - 
			dot=FL_DOT,               // .......
			dashdot=FL_DASHDOT,       // - . - .
			dashdotdot=FL_DASHDOTDOT, // -..-.. 
  };
  Line_style(Line_style_type ss) :s(ss), w(0) { }
  Line_style(Line_style_type lst, int ww) :s(lst), w(ww) { }
  Line_style(int ss) :s(ss), w(0) { }
  int width() const { return w; }
  int style() const { return s; }
private:
  int s;
  int w;
};

/*3 : Color*/
struct Color {
  enum Color_type {
		   red=FL_RED, blue=FL_BLUE, green=FL_GREEN,
		   yellow=FL_YELLOW, white=FL_WHITE, black=FL_BLACK,
		   magenta=FL_MAGENTA, cyan=FL_CYAN, dark_red=FL_DARK_RED,
		   dark_green=FL_DARK_GREEN, dark_yellow=FL_DARK_YELLOW, dark_blue=FL_DARK_BLUE,
		   dark_magenta=FL_DARK_MAGENTA, dark_cyan=FL_DARK_CYAN
  };
  enum Transparency { invisible = 0, visible=255 };
  Color(Color_type cc) :c(Fl_Color(cc)), v(visible) { }
  Color(Color_type cc, Transparency vv) :c(Fl_Color(cc)), v(vv) { }
  Color(int cc) :c(Fl_Color(cc)), v(visible) { }
  Color(Transparency vv) :c(Fl_Color()), v(vv) { }
  int as_int() const { return c; }
  char visibility() const { return v; }
  void set_visibility(Transparency vv) { v=vv; }
private:
  unsigned char v;    // 0 or 1 for now 
  Fl_Color c;
};

class Shape {
public:
  void draw() const;
  virtual void move(int dx, int dy);
  void set_color(Color col){lcolor=col;}
  Color color() const{return lcolor;}
  void set_style(Line_style sty){ls=sty;}
  Line_style style() const{return ls;}
  void set_fill_color(Color col){fcolor=col;}
  Color fill_color() const{return fcolor;}
  Point point(int i) const{return points.at(i);}
  int number_of_points() const{return points.size();}
  Shape(const Shape&) = delete;
  Shape& operator=(const Shape&) = delete;
  virtual ~Shape() { }
protected:
  Shape() { }
  Shape(std::initializer_list<Point> lst){
    for(Point p : lst)
      add(p);
  }
  virtual void draw_lines() const;
  void add(Point p);
  void set_point(int i, Point p){points.at(i)=p;}
private:
  std::vector<Point> points;
  Color lcolor {fl_color()};
  Line_style ls {0};
  Color fcolor {Color::invisible};
};

void Shape::add(Point p){ points.push_back(p); }
void Shape::draw_lines() const{
  for(int i=1;i<number_of_points();i+=2)
    fl_line(point(i-1).x,point(i-1).y,point(i).x,point(i).y);
}
void Shape::draw() const{
  Fl_Color oldc = fl_color();
  fl_color(lcolor.as_int());                // set color
  fl_line_style(ls.style(),ls.width());     // set style
  draw_lines();
  fl_color(oldc);                          // reset color (to previous)
  fl_line_style(0);                        // reset the linestyle to the default
}

void Shape::move(int dx, int dy){
  for(size_t i=0;i<points.size();++i){
    points.at(i).x+=dx;
    points.at(i).y+=dy;
  }
}

int main(int argc,char **argv){
  /* it generate compile erorr due to protected keyword
     so it is designed to be a base class
  Shape ss; 
  */
  return 0;
}
