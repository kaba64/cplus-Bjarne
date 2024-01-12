#include <iostream>

struct Point{
  double x;                                                                                                                       
  double y;
};

constexpr double scale_x = 10;
constexpr double scale_y = 0.8;

constexpr Point scale(Point p){return {scale_x*p.x,scale_y*p.y};} 

inline void printp(const Point pIn,const std::string name){std::cout<<name<<" = ("<<pIn.x<<","<<pIn.y<<")\n";}

void printPoints(Point p1){
  
  printp(p1,"p1");

  constexpr Point p0{1.5,1.5};
  std::cout<<"use (constexpr Point scale) function for a non-constant input," 
    " but the result is stored in a non-constant variable: Ok!\n ";

  Point p2 = scale(p1); // it will be evaluated at run time
  printp(p2,"p2");

  std::cout<<"use (constexpr Point scale) function for a constant input,"
    " and the result is stored in a constant variable: Ok!\n ";
  constexpr Point p3 = scale(p0);
  printp(p3,"p3");

  /*Uncommenting the below line will produce compile time error since p1 is not constexpr*/
  //constexpr Point p4 = scale(p1);
}

int main(int argc,char *argv[]){

  std::cout<<"Please enter a point (x,y) : x followed by y\n";
  Point p1;
  std::cin>>p1.x;
  std::cin>>p1.y;
  printPoints(p1);
  return 0;
}
