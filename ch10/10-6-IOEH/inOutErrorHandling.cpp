#include <iostream>
#include <fstream>
#include <exception>
#include <vector>

template<typename T> void fill_vector(std::istream &input,std::vector<T> &data,const char terminate){

  for(int i;input>>i;)
    data.push_back(i);
  if(input.bad())
    throw std::runtime_error("input is bad");
  if(input.eof())
    return;
  if(input.fail()){
    input.clear(); /*clear the stream state*/
    char c;
    input>>c;
    if(c!=terminate){
      input.unget();
      input.clear(std::ios_base::failbit); /*set the state to fail()*/
    }
  }
}

template<typename T> void printContainer(const std::vector<T>& dataP,const std::string name){
  for(auto it=dataP.begin();it!=dataP.end();++it){
    unsigned int idx = std::distance(dataP.begin(),it);
    std::cout<<name<<"["<<idx<<"] = "<<*it<<"\n";
  }
}

int main(int argc,char **argv){

  std::fstream input;
  input.open("dataWithAsterisk.txt",std::ios_base::in);
  std::vector<int> data;

  try{
    fill_vector(input,data,'$');
  }catch(const std::exception& e){
    std::cerr << "Exception: " << e.what() <<"\n";
  }
  
  if(input.fail()){
    input.clear(); // the istream should be in good() state to use .get()
    char c = input.get();
    std::cout<<"The character in the data is : "<<c<<"\n";
  }
  input.close();
  
  printContainer(data,"data");
  
  return 0;
}
