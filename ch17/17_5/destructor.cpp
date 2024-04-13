#include <iostream>

class vector{
public:
  vector(size_t s)
    :sz{s},elem{new double[s]}
  {
    std::cout<<"Constructor of vector\n";
    for(size_t i=0;i<s;++i)elem[i]=i*1.;
  }
  ~vector(){std::cout<<"Destructor of vector\n";delete[] elem;}
  int size() const{return sz;}
  int element(size_t i) const{return elem[i];}
private:
  size_t sz;
  double* elem;
};

int main(int argc,char** argv){
  vector v1{2};
  std::cout<<"v1[0] = "<<v1.element(0)<<" , v1[1] = "<<v1.element(1)<<"\n";
  return 0;
}
