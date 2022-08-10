#include <iostream>
#include <fstream>
#include <vector>

class Point{
public:
  Point(double xin,double yin)
    :x{xin},y{yin}{}
  double x,y;
};

auto main() -> int
{
  std::vector<Point> points;
  std::cout<<"Please enter a name for the output file"<<"\n";
  std::string oname;
  std::cin>>oname;
  std::ofstream ost{oname+".txt"};
  if(!ost) std::cout<<"Hi"<<"\n";

  std::cout<<"Please enter the points x and y"<<"\n";
  for(double x,y;std::cin>>x>>y;){
    Point p{x,y};
    points.push_back(p);
  }
  for(unsigned int i=0;i<points.size();++i)
    ost<<points[i].x<<"\t"<<points[i].y<<"\n";
}
