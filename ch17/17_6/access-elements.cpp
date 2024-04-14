#include <iostream>

class vector{
public:
  vector(int s):sz{s},elem{new double[s]}{
    for(int i=0;i<s;++i)elem[i]=0.0;
  }
  ~vector(){delete[] elem;}
  int size() const{return sz;}
  double get(int i) const{return elem[i];}
  void set(int n,double v){elem[n]=v;}
private:
  int sz;
  double* elem;
};

int main(int argc,char **argv){
  vector v1(6);
  
  for(int i=0;i<v1.size();++i){
    v1.set(i,i*2.);
    std::cout<<"v1["<<i<<"] = "<<v1.get(i)<<"\n";
  }
  return 0;
}
