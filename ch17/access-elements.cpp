#include <iostream>

class vector{
  int sz;
  double* elem;
public:
  vector(int s)
    :sz{s},
     elem{new double[s]}{for(int i=0;i<s;++i)elem[i]=0.;}
  ~vector(){delete[] elem;}
  int size() const{return sz;}
  double get(int i) const{return elem[i];}
  void set(int n,double v){elem[n]=v;}
};

auto main() -> int
{
  vector v1{2};
  v1.set(0,55.);
  v1.set(1,88.);
  std::cout<<"v1[0] = "<<v1.get(0)<<" , v1[1] = "<<v1.get(1)<<std::endl;
}
