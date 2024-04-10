#include <iostream>
#include <exception>
#include <string>
#include <vector>

struct Person{
  Person(std::string nameIn="",size_t ageIn=0){
    try{
      testAge(ageIn);
      testName(nameIn);
    }catch(const std::exception & e){
      std::cerr<<"Error in constructor : "<<e.what()<<"\n";
    }
  }
  std::string name()const{return namep;}
  size_t age()const{return agep;}
private:
  void testAge(int ageIn);
  void testName(std::string nameIn);
  std::string namep;
  size_t agep;
};

void Person::testAge(int ageIn){
  if(!(ageIn>=0 && ageIn<150))
    throw std::runtime_error("Age is not in the range [0,150)");
  agep = ageIn;
}

void Person::testName(std::string nameIn){
  std::vector<char> charCheck{';', ':', '"', '\'', '[', ']', '*', '&', '^', '%', '$', '#', '@', '!'};
  for(auto it = nameIn.cbegin();it!=nameIn.cend();++it){
    for(auto itc = charCheck.cbegin();itc!=charCheck.cend();++itc){
      if(*it==*itc){
	std::string error = "Bad character \"";
	error+=*it;
	error+="\" is in the input name";
	throw std::runtime_error(error);
      }
    }
  }
  namep=nameIn;
}

std::ostream& operator <<(std::ostream& out,Person& pOut){
  out<<"("<<pOut.name()<<","<<pOut.age()<<")";
  return out;
}

std::istream& operator >>(std::istream& is,Person& pIn){
  /*format : (name,age)*/
  std::string name;
  size_t age{0};
  
  try{
    char ch1,ch2,ch3;
    is>>ch1>>name>>ch2>>age>>ch3;
    if(ch1!='(' || ch2!= ',' || ch3!=')')
      throw std::runtime_error("Bad format input");
  }catch(const std::exception & e){
    std::cerr<<"Error in >> : "<<e.what()<<"\n";
    is.clear(std::ios_base::failbit);
    return is;
  }

  Person test{name,age};
  pIn = test;
  return is;
}

int main() {

  Person newMember{"Goofy",63};
  std::cout<<"Write 2 : without overloaded opertors\n";
  std::cout<<"("<<newMember.name()<<","<<newMember.age()<<")\n";
  std::cout<<"\n";

  std::cout<<" 2 and 3 : give the input in format ( name , age )\n";
  Person IOTest;
  std::cin>>IOTest;
  std::cout<<IOTest<<"\n";
  std::cout<<"\n";
  
  std::cout<<" 8 : read to vector container and write to standard output ( name , age )\n";
  std::cout<<"Enter ctrl+D to terminate reading\n";
  std::vector<Person> personVev;
  for(Person inP;std::cin>>inP;){
    personVev.push_back(inP);
  }
  for(size_t i =0;i<personVev.size();++i){
    std::cout<<personVev.at(i)<<"\n";
  }
  return 0;
}
