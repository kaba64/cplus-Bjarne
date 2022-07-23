#include <iostream>
//#include <vector>

class vector{
  int sz;
  double* elem;
public:
  vector(int s);
  int size() const{return sz;}
};

auto main() -> int
{
  int var =17;
  int *ptr = &var;
  int newd = ptr;
  std::cout<<ptr<<std::endl;
  std::vector<double> age(4);
  //age[0]=0.33;
  //age[1]=22.0;
  //age[2]=27.2;
  //age[3]=54.2;
}
