#include <iostream>
#include <exception>
#include "vector.h"

/*Default constructor*/
template<typename T,typename A> vector<T,A>::vector():sz(0),elem(nullptr),space(0){}
/*Constructor*/
template<typename T,typename A> vector<T,A>::vector(size_t s,T value)
  :sz(s),elem(alloc.allocate(s)),space(s){
  std::uninitialized_fill(elem,&elem[sz],value); /*initialize elements*/ 
}
/*copy constructor*/
template<typename T,typename A> vector<T,A>::vector(const vector<T,A>& src):sz(src.sz),elem(alloc.allocate(sz)),space(sz){
  std::copy(src.elem,src.elem+src.sz,elem);
}
/*list constructor*/
template<typename T,typename A> vector<T,A>::vector(std::initializer_list<T> lst):sz(lst.size()),elem(alloc.allocate(sz)),
										  space(lst.size()){
  std::copy(lst.begin(),lst.end(),elem);
}
/*move constructor*/
template<typename T,typename A> vector<T,A>::vector(vector<T,A>&& src):sz(src.sz),elem(src.elem),space(src.space){
  src.sz=0;
  src.space=0;
  src.elem=nullptr;
}
/*copy assignment*/
template<typename T,typename A> vector<T,A>& vector<T,A>::operator =(const vector<T,A>& src){
  if(&src==this)
    return *this;
  if(src.sz<=space){
    std::copy(src.elem,src.elem+src.sz,elem);
    sz=src.sz;
    return *this;
  }
  T* p = alloc.allocate(src.sz);              /*allocate new space*/
  std::copy(src.elem,src.elem+src.sz,p);      /*copy elements*/
  std::destroy(elem,&elem[space]);            /*destroy old elements*/
  alloc.deallocate(elem,capacity());          /*deallocate old space*/
  elem = p;
  sz = src.sz;
  space=sz;
  return *this;
}
/*move assignment*/
template<typename T,typename A> vector<T,A>& vector<T,A>::operator =(vector<T,A>&& src){
  std::destroy(elem,&elem[space]);
  alloc.deallocate(elem,capacity());
  elem = src.elem;
  sz = src.sz;
  space=src.space;
  src.elem=nullptr;
  src.sz=0;
  src.space=0;
  return *this;
}
/*get rvalu*/
template<typename T,typename A> T vector<T,A>::operator [](size_t i)const{
  return elem[i];
}
/*get lvalue*/
template<typename T,typename A> T& vector<T,A>::operator [](size_t i){
  return elem[i];
}
/*get lvalue with range check*/
template<typename T,typename A> T& vector<T,A>::at(size_t i){
  if(i<0 || i>=sz)
    throw std::out_of_range("Index out of range");
  return elem[i];
}
/*get rvalue with range check*/
template<typename T,typename A> const T& vector<T,A>::at(size_t i)const{
  if(i<0 || i>=sz)
    throw std::out_of_range("Index out of range");
  return elem[i];
}
template<typename T,typename A> void vector<T,A>::reserve(size_t newalloc){
  
  if(newalloc<=space){
    return;
  }
  T* p = alloc.allocate(newalloc);
  std::uninitialized_move(elem,&elem[sz],p);
  std::destroy(elem,&elem[space]);
  alloc.deallocate(elem,capacity());
  elem=p;
  space=newalloc;
}
template<typename T,typename A> size_t vector<T,A>::capacity()const{return space;}
template<typename T,typename A> void vector<T,A>::resize(size_t newsize,T def){
  reserve(newsize);
  if(sz<newsize){
    std::uninitialized_fill(&elem[sz],&elem[newsize],def); /*initialize added elements to def*/
  }
  if(newsize<sz){
    std::destroy(&elem[newsize],&elem[sz]);
  }
  sz=newsize;
}
template<typename T,typename A> void vector<T,A>::push_back(T d){
  if(space==0)
    reserve(8);
  else if(sz==space)
    reserve(2*space);
  std::construct_at(&elem[sz],d);
  ++sz;
}
template<typename T,typename A> void vector<T,A>::print_vector(const std::string& name)const{
  for(size_t i=0;i<sz;++i){
    std::cout<<name<<"["<<i<<"] = "<<elem[i]<<"\t";
    if(i==sz-1 || (i+1)%3==0)
      std::cout<<"\n";
  }
}
template<typename T,typename A> vector<T,A>::~vector(){
  std::destroy(elem,&elem[space]);
  alloc.deallocate(elem,capacity());
}
