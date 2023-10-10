#include <iostream>
#include "area.h"

auto main() -> int
{
  try{
    int x = -1;
    int y = 2;
    int z = 4;
    
    int area1 = area(x,y);
    int area2 = framed_area(1,z);
    int area3 = framed_area(y,z);
    double ratio = double(area1)/area3;
    std::cout<<"area1 = "<<area1<<"\n";
    std::cout<<"area2 = "<<area2<<"\n";
    std::cout<<"area3 = "<<area3<<"\n";
    std::cout<<"ratio = "<<ratio<<"\n";
  }
  catch(Bad_area){
    std::cout<<"Bad argument to area()\n";
  }
}
