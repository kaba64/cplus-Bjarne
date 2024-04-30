#include <iostream>
#include <exception>
#include "vector.h"

template<typename T> vector<T>::vector():sz(0),elem(nullptr),space(0){}

template<typename T> vector<T>::vector(size_t s,T value)
  :sz(s),elem(new T[s]),space(s){
  for(size_t i=0;i<s;++i){
    elem[i]=value;
  }
}

template<typename T> vector<T>::vector(const vector<T>& src):sz(src.sz),elem(new T[sz]),space(sz){
  std::copy(src.elem,src.elem+sz,elem);
}
template<typename T> vector<T>::vector(std::initializer_list<T> lst):sz(lst.size()),elem(new T[sz]),space(lst.size()){
  std::copy(lst.begin(),lst.end(),elem);
}
template<typename T> vector<T>::vector(vector<T>&& src):sz(src.sz),elem(src.elem),space(src.space){
  src.sz=0;
  src.space=0;
  src.elem=nullptr;
}
template<typename T> vector<T>& vector<T>::operator =(const vector<T>& src){
  if(&src==this)
    return *this;
  if(src.sz<=space){
    std::copy(src.elem,src.elem+src.sz,elem);
    sz=src.sz;
    return *this;
  }
  double* p = new T[src.sz];
  std::copy(src.elem,src.elem+src.sz,p);
  delete[] elem;
  elem = p;
  sz = src.sz;
  space=sz;
  return *this;
}
template<typename T> vector<T>& vector<T>::operator =(vector<T>&& src){
  delete[]elem;
  elem = src.elem;
  sz = src.sz;
  space=src.space;
  src.elem=nullptr;
  src.sz=0;
  src.space=0;
  return *this;
}
template<typename T> T vector<T>::operator [](size_t i)const{
  return elem[i];
}
template<typename T> T& vector<T>::operator [](size_t i){
  return elem[i];
}
template<typename T> void vector<T>::reserve(size_t newalloc){
  
  if(newalloc<=space){
    std::string msg;
    if(newalloc<=0){
      msg = "The arguent for reserve() method is negative : "+std::to_string(newalloc);
      throw std::runtime_error(msg);
      return;
    }
    return;
  }
  double* p = new T[newalloc];
  for(size_t i=0;i<sz;++i)
    p[i]=elem[i];
  delete[] elem;
  elem=p;
  space=newalloc;
}
template<typename T> size_t vector<T>::capacity()const{return space;}
template<typename T> void vector<T>::resize(size_t newsize){
  try{
    reserve(newsize);
    for(size_t i=sz;i<newsize;++i)
      elem[i]=0.0;
    sz=newsize;
  }catch(const std::exception& e){
    std::cerr<<"Error : "<<e.what()<<"\n";
  }
}
template<typename T> void vector<T>::push_back(T d){
  if(space==0)
    reserve(8);
  else if(sz==space)
    reserve(2*space);
  elem[sz]=d;
  ++sz;
}
template<typename T> void vector<T>::print_vector(const std::string& name)const{
  for(size_t i=0;i<sz;++i){
    std::cout<<name<<"["<<i<<"] = "<<elem[i]<<"\t";
    if(i==sz-1 || (i+1)%3==0)
      std::cout<<"\n";
  }
}
template<typename T> vector<T>::~vector(){
  delete[] elem;
}
