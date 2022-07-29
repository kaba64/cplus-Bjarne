#include <iostream>

class vector{
  int sz;
  double* elem;
public:
  vector(int s)
    :sz{s},
     elem{new double[s]}
  {
    for(int i=0;i<s;++i)elem[i]=i*1.;
  }
  ~vector()
  {
    delete[] elem;
  }
  int size() const
  {
    return sz;
  }
  int content(int i) const
  {
    return elem[i];
  }
};

auto main() -> int
{
  vector v1{2};
  std::cout<<"v1[0] = "<<v1.content(0)<<" , v1[1] = "<<v1.content(1)<<std::endl;
}
