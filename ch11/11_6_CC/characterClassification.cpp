#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <span>
#include <exception>

bool is_special_char(char c) {
    return c == '+' || c == '/' || c == '*' || c == '<' || c == '=';
}

template<typename T> void readInputChar(std::ifstream &ifo,std::vector<T> &inputChar){

  for(T ch;ifo.get(ch);){
    if(std::isspace(ch)){
      /*Do nothing*/
    }else if(std::isdigit(ch) || std::isalpha(ch)){
      /*Read a number and identifier*/
      inputChar.push_back(ch);
    }else if(is_special_char(ch)){
      inputChar.push_back(ch);
    }else{
      throw std::runtime_error("Undefined input");
    }
  }

}

template<typename T> void showContainer(std::span<T> container,std::string name){
  for(auto it = container.begin();it!=container.end();++it){
    int index = std::distance(container.begin(),it);
    std::cout<<name<<"["<<index<<"] = "<<*it<<"\n";
  }
}

int main(int argc,char **argv){

  std::ifstream ifo;
  std::string iName;
  std::vector<char> inputChar;
  
  std::cout<<"Please enter the name of the file without .txt extension : ";
  std::cin>>iName;
  std::cout<<"\n\n";
  
  iName+=".txt";
  ifo.open(iName,std::ios_base::in);

  try{
    readInputChar(ifo,inputChar);
  }catch(const std::exception & e){
    std::cerr<<e.what()<<"\n";
  }
  
  ifo.close();

  showContainer<char>(inputChar,"words");
  
  return 0;
}
