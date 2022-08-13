#include <iostream>

class vector{
public:
  vector(int s)
    :sz{s},elem{new double[s]}
  {
    for(int i=0;i<s;++i)elem[i]=i*1.;
  }
  ~vector(){delete[] elem;}
  int size() const{return sz;}
  int element(int i) const{return elem[i];}
private:
  int sz;
  double* elem;
};

auto main() -> int
{
  vector v1{2};
  std::cout<<"v1[0] = "<<v1.element(0)<<" , v1[1] = "<<v1.element(1)<<"\n";
}
