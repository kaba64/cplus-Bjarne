#include <iostream>
#include <exception>
#include "vector.h"

vector::vector()
  :sz(0),elem(nullptr),space(0){std::cout<<"Default constructor\n";}
vector::vector(size_t s,double value)
  :sz(s),elem(new double[s]),space(s){
  std::cout<<"Constructor\n";
  for(size_t i=0;i<s;++i){
    elem[i]=value;
  }
}
vector::vector(const vector& src):sz(src.sz),elem(new double[sz]),space(src.space){
  std::cout<<"Copy constructor\n";
  std::copy(src.elem,src.elem+sz,elem);
}
vector::vector(std::initializer_list<double> lst):sz(lst.size()),elem(new double[sz]),space(lst.size()){
  std::cout<<"Initializer list constructor\n";
  std::copy(lst.begin(),lst.end(),elem);
}
vector::vector(vector&& src):sz(src.sz),elem(src.elem),space(src.space){
  std::cout<<"Move constructor\n";
  src.sz=0;
  src.space=0;
  src.elem=nullptr;
}
vector& vector::operator =(const vector& src){
  std::cout<<"Copy assignment\n";
  double* p = new double[src.sz];
  std::copy(src.elem,src.elem+src.sz,p);
  delete[] elem;
  elem = p;
  sz = src.sz;
  space=src.space;
  return *this;
}
vector& vector::operator =(vector&& src){
  std::cout<<"Move assignment\n";
  delete[]elem;
  elem = src.elem;
  sz = src.sz;
  space=src.space;
  src.elem=nullptr;
  src.sz=0;
  src.space=0;
  return *this;
}
double vector::operator [](size_t i)const{
  std::cout<<"[](size_t i)const\n";
  return elem[i];
}
double& vector::operator [](size_t i){
  std::cout<<"[](size_t i)\n";
  return elem[i];
}
void vector::reserve(size_t newalloc){
  
  if(newalloc<=space){
    std::string msg;
    if(newalloc<=0){
      msg = "The arguent for reserve() method is negative : "+std::to_string(newalloc);
      throw std::runtime_error(msg);
      return;
    }
    return;
  }
  double* p = new double[newalloc];
  for(size_t i=0;i<sz;++i)
    p[i]=elem[i];
  delete[] elem;
  elem=p;
  space=newalloc;
}
size_t vector::capacity()const{return space;}
void vector::resize(size_t newsize){
  try{
    reserve(newsize);
    for(size_t i=sz;i<newsize;++i)
      elem[i]=0.0;
    sz=newsize;
  }catch(const std::exception& e){
    std::cerr<<"Error : "<<e.what()<<"\n";
  }
}
void vector::print_vector(const std::string& name)const{
  for(size_t i=0;i<sz;++i){
    std::cout<<name<<"["<<i<<"] = "<<elem[i]<<"\t";
    if(i==sz-1 || (i+1)%3==0)
      std::cout<<"\n";
  }
}
vector::~vector(){
  std::cout<<"Destructor\n";
  delete[] elem;
}
