#include <std_lib_facilities.h>
#include "area.h"

int area(int lenght,int height)
{
  return lenght*height;
}

int framed_area(int x, int y)
{
  constexpr int frame_width = 2;
  if(x-frame_width<=0 || y-frame_width<=0)
    error("non-positive area() arguments called by framed_area()");
  return area(x-frame_width,y-frame_width);
}
