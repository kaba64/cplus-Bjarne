#include <iostream>
#include <string>
#include <initializer_list>

class vector{
public:
  explicit vector(size_t s,double value=0);
  vector(std::initializer_list<double> lst);
  vector(const vector& src);                  /*copy constructor*/
  vector& operator =(const vector& src);      /*copy assignment*/
  vector(vector&& src);                       /*move constructor*/
  vector& operator =(vector&& src);           /*move assignment*/
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
vector::vector(vector&& src):sz(src.sz),elem(src.elem){
  std::cout<<"Move constructor\n";
  src.sz=0;
  src.elem=nullptr;
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
vector& vector::operator =(vector&& src){
  std::cout<<"Move assignment\n";
  delete[]elem;
  elem = src.elem;
  sz = src.sz;
  src.elem=nullptr;
  src.sz=0;
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

int main(int argc,char** argv){
  /*If the constructor with one argument is not explicit
   the following segment of code will do implicit conversion!
  */
  
  vector vec = 20;
  vec.print_vector("vec");
  
  return 0;
}
