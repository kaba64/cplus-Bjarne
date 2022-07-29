#include <iostream>

class vector{
  int sz;
  double* elem;
public:
  vector(int s)
    :sz{s},
     elem{new double[s]}{for(int i=0;i<s;++i)elem[i]=1.1*i;}
  ~vector(){delete[] elem;}
  int size() const{return sz;}
  double get(int i) const{return elem[i];}
  void set(int n,double v){elem[n]=v;}
};

vector* f(int s){
  vector* p = new vector(s);
  return p;
}

void ff()
{
  vector* q=f(4);
  delete q;
}
  
auto main() -> int
{
  vector* p = new vector(4);
  int x = p->size();
  double d = p->get(3);
  std::cout<<"size "<<x<<" , p[3] = "<<d<<std::endl;
}
