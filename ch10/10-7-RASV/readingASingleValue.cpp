#include <iostream>
#include <exception>
#include <vector>
#include <typeinfo>
#include <string>

bool stringIsdigit(std::string chIn){
  for(char c : chIn){
    if(!std::isdigit(c))
      return false;
  }
  return true;
}

template<typename T> void skip_to_next(std::istream & cin,T & singleInput,bool & flag){
  int count{0}; /*Read 10 times*/
  if(std::cin.fail()){
    std::cin.clear();
    for(std::string ch;(std::cin>>ch && count<10);){
      count+=1;
      if(stringIsdigit(ch) || static_cast<char>(*ch.c_str())=='-'){
	singleInput =  std::stoi(ch);
	return;
      }else if(std::cin.eof()){
	flag = false;
	return;
      }else if(std::cin.bad()){
	throw std::runtime_error("bad input");
	flag = false;
	return;
      }
    }
  }else if(std::cin.bad()){
    throw std::runtime_error("bad input");
    flag = false;
    return;
  }
}

template<typename T> void get_input(T & singleInput,bool & flag){
  
  std::cin>>singleInput;
  if(std::cin.eof()){
    flag = false;
    return;
  }else if(!(std::cin.good())){
    std::cout<<"Sorry that was not a number; please try again\n";
    skip_to_next(std::cin,singleInput,flag);
  }
}

template<typename T> std::vector<T> get_input(const T a1,const T a2){

  std::cout<<"Please enter a number in the range ["<<a1<<","<<a2<<"]\n";
  bool flag{true};
  std::vector<T> dataIn;
  T singleInput{0};
  try{
    while(flag){
      get_input(singleInput,flag);
      if(singleInput>=1 && singleInput<=10){
	dataIn.push_back(singleInput);
      }else if(flag==true){
	std::cout<<"Sorry "<<singleInput<<" is not in the range ["<<a1<<","<<a2<<"]; please try again\n";
      }
    }
  }catch(const std::exception& e){
    std::cerr<<"Error : "<<e.what()<<"\n";
  }
  return dataIn;
}

template<typename T> void printContainer(const std::vector<T>& dataP,const std::string name){
  for(auto it=dataP.begin();it!=dataP.end();++it){
    unsigned int idx = std::distance(dataP.begin(),it);
    std::cout<<name<<"["<<idx<<"] = "<<*it<<"\n";
  }
}

int main(int argc,char **argv){
  
  std::vector<int> dataInt = get_input(1,10);
  printContainer(dataInt,"dataInt");
  
  return 0;
}
