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
