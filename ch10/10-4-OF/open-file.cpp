#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <string>

class Point{
public:
  Point(double xin,double yin)
    :x{xin},y{yin}{}
  double x,y;
};

int main(int argc,char **argv){
  
  std::vector<Point> points;
  std::cout<<"Please enter a name for the output file"<<"\n";
  std::string oname;
  std::cin>>oname;
  try{
    std::ofstream ost{oname+".txt"};
    if(!ost) {
      std::string error_m{"Error in opention "+oname+" file."};
      throw std::runtime_error(error_m);
    }
    
    std::cout<<"Please enter the points x and y"<<"\n";
    for(double x,y;std::cin>>x>>y;){
      Point p{x,y};
      points.emplace_back(p);
    }
    for(unsigned int i=0;i<points.size();++i)
      ost<<points[i].x<<"\t"<<points[i].y<<"\n";
  }catch(const std::exception& e){
    std::cerr << "Exception: " << e.what() <<"\n";
  }
  return 0;
}
