#include <iostream>
#include <string>
#include <initializer_list>

class vector{
public:
  vector(size_t s,double value=0);
  vector(std::initializer_list<double> lst);
  vector(const vector& src);
  vector& operator =(const vector& src);
  ~vector();
  size_t size() const{return sz;}
  double get(size_t i) const{return elem[i];}
  void set(size_t n,double v){elem[n]=v;}
  void print_vector(const std::string& name)const;
private:
  size_t sz;
  double* elem;
};

vector::vector(size_t s,double value)
  :sz(s),elem(new double[s]){
  std::cout<<"Default constructor\n";
  for(size_t i=0;i<s;++i){
    elem[i]=value;
  }
}

vector::vector(const vector& src):sz(src.sz),elem(new double[sz]){
  std::cout<<"Copy constructor\n";
  std::copy(src.elem,src.elem+sz,elem);
}
vector::vector(std::initializer_list<double> lst):sz(lst.size()),elem(new double[sz]){
  std::cout<<"Initializer list constructor\n";
  std::copy(lst.begin(),lst.end(),elem);
}
vector& vector::operator =(const vector& src){
  std::cout<<"Copy assignment\n";
  double* p = new double[src.sz];
  std::copy(src.elem,src.elem+src.sz,p);
  delete[] elem;
  elem = p;
  sz = src.sz;
  return *this;
}
vector::~vector(){
  std::cout<<"Destructor\n";
  delete[] elem;
}
void vector::print_vector(const std::string& name)const{
  for(size_t i=0;i<sz;++i){
    std::cout<<name<<"["<<i<<"] = "<<elem[i]<<"\t";
    if(i==sz-1 || (i+1)%3==0)
      std::cout<<"\n";
  }
}

void f_copy(){
  const size_t size{3};
  const size_t size2{4};
  vector v(size);
  v.set(size-1,2.2);
  vector v2(size2,1);
  v.print_vector("v");
  v2.print_vector("v2");
  v2 = v;
  v.print_vector("v");
  v2.print_vector("v2");
}

int main(int argc,char** argv){
  std::cout<<"\nBefore f_copy() functions\n\n";
  f_copy();
  std::cout<<"\nAfter f_copy() functions\n\n";
  return 0;
}
