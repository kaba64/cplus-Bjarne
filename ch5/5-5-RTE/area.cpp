#include "area.h"

int area(int lenght,int height)
{
  return lenght*height;
}

int framed_area(int x, int y)
{
  return area(x-2,y-2);
}
