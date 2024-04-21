#include <iostream>
#include <string>
#include <initializer_list>

class vector{
public:
  vector(size_t s,double value=0);
  vector(std::initializer_list<double> lst);
  ~vector(){delete[] elem;}
  size_t size() const{return sz;}
  double get(size_t i) const{return elem[i];}
  void set(size_t n,double v){elem[n]=v;}
  void print_vector()const;
private:
  size_t sz;
  double* elem;
};

vector::vector(size_t s,double value)
  :sz(s),elem(new double[s]){
  std::cout<<"Constructor\n";
  for(size_t i=0;i<s;++i){
    elem[i]=value;
  }
}
vector::vector(std::initializer_list<double> lst):sz(lst.size()),elem(new double[sz]){
  std::cout<<"Initializer list constructor\n";
  std::copy(lst.begin(),lst.end(),elem);
}

void vector::print_vector()const{
  std::string name = "vector"+std::to_string(sz);
  for(size_t i=0;i<sz;++i){
    std::cout<<name<<"["<<i<<"] = "<<elem[i]<<"\t";
    if(i==sz-1 || (i+1)%3==0)
      std::cout<<"\n";
  }
}

int main(int argc,char** argv){

  const size_t size{3};
  vector vector3(size);
  vector3.print_vector();
  vector vectorList3{1.2,2.4,4.8};
  vectorList3.print_vector();
  return 0;
}
