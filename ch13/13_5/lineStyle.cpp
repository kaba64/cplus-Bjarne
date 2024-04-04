#include <iostream>
#include <exception>
#include "./../utils/Simple_window.h"
#include "./../utils/Graph.h" 

int main() {

  try{
    using namespace Graph_lib;

    Point x{100,100};
    Simple_window win{x,600,400,"grid"};

    int x_size{win.x_max()};
    int	y_size{win.y_max()};
    int x_grid{80};
    int y_grid{40};

    Lines grid;
    for(int x=x_grid;x<x_size;x+=x_grid)
      grid.add(Point{x,0},Point{x,y_size});
    
    for(int y=y_grid;y<y_size;y+=y_grid)
      grid.add(Point{0,y},Point{x_size,y});

    /*13-4 : Color*/
    grid.set_color({Color::red,Color::visible});
    /* uncommenting this will make the lines invisible 
      grid.set_color({Color::red,Color::invisible});
     */
    /*End 13-4 : Color*/
    /*13-5 : Line_style*/
    std::cout<<"line style before change : "<<(grid.style()).style()<<"\n";
    std::cout<<"line width before change : "<<(grid.style()).width()<<"\n";
    grid.set_style(Line_style{Line_style::dash,2});
    std::cout<<"line style before change : "<<(grid.style()).style()<<"\n";
    std::cout<<"line width before change : "<<(grid.style()).width()<<"\n";
    /*End 13-5 : Line_style*/
    win.attach(grid);
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