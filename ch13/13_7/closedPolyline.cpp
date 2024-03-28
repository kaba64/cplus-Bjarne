#include <iostream>
#include <exception>
#include "./../utils/Simple_window.h"
#include "./../utils/Graph.h" 

int main() {

  try{
    using namespace Graph_lib;
    Point x{100,100};
    Simple_window win{x,600,400,"closedPolyline"};
    
    /*13-7 : closed_polyline*/
    Closed_polyline cpl;
    
    cpl.add(Point{100,100});
    cpl.add(Point{150,200});
    cpl.add(Point{250,250});
    cpl.add(Point{300,200});
    win.attach(cpl);
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
