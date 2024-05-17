#include <iostream>
#include <string>
#include "vector.h"

template<typename T> struct S{
  S(T valIn=T{}): val(valIn){}
  const T get()const{return val;}
  T& get(){return val;}
  T& operator =(const T& valIn){return val;} 
private:
  T val;
};

template<typename T> void printS(const S<T> & input,const std::string name){
  //std::cout<<name<<" = "<<input.val<<"\n";
  /*After adding get() member function*/
  std::cout<<name<<" = "<<input.get()<<"\n";
}

template<typename T> void read_val(T& v,const std::string name){
  std::cout<<"Please enter an "<<name<<"\n";
  std::cin>>v;
}

int main(int argc,char** argv){
  //S<int> IntOne(1);
  //S<char> charOne('C');
  //S<double> doubleOne(3.14);
  //S<std::string> stringOne("Hi!");
  S<int> IntOne;
  S<char> charOne('C');
  S<double> doubleOne(3.14);
  S<std::string> stringOne("Hi!");
  /*The use of read_val function*/
  read_val(IntOne.get(),"int");
  read_val(charOne.get(),"char");
  read_val(doubleOne.get(),"double");
  read_val(stringOne.get(),"string");
  
  S<vector<int>> vectorOne;
  for(size_t i=0;i<5;++i){
    //vectorOne.val.push_back(i);
    vectorOne.get().push_back(i);
  }
  printS(IntOne,"IntOne");
  printS(charOne,"charOne");
  printS(doubleOne,"doubleOne");
  printS(stringOne,"stringOne");
  //vectorOne.val.print_vector("vectorOne");
  vectorOne.get().print_vector("vectorOne");
  return 0;
}
