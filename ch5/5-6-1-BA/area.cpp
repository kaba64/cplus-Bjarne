#include <exception>
#include "area.h"

int area(int lenght,int height)
{
  if(lenght<=0 || height<=0) throw Bad_area{};
  return lenght*height;
}

int framed_area(int x, int y)
{
  return area(x-2,y-2);
}
