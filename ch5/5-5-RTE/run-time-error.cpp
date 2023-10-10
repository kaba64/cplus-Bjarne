#include <std_lib_facilities.h>
#include <iostream>
#include "area.h"

int area(int,int);

auto main() -> int
{
  int x = -1;
  int y = 2;
  int z = 4;

  if (x<=0) error("non-positive x");
  if (y<=0) error("non-positive y");
  
  int area1 = area(x,y);
  int area2 = framed_area(1,z);
  int area3 = framed_area(y,z);
  double ratio = double(area1)/area3;
  std::cout<<"area1 = "<<area1<<"\n";
  std::cout<<"area2 = "<<area2<<"\n";
  std::cout<<"area3 = "<<area3<<"\n";
  std::cout<<"ratio = "<<ratio<<"\n";
}
