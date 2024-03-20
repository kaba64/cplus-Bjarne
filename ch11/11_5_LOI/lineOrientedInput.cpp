#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <span>
#include <exception>

void readInOneLine(std::istream & ifo,std::stringstream & input){

  std::string line;
  if (std::getline(ifo, line) || ifo.eof()) {
    // Clear the stringstream before appending new content
    input.str("");
    input.clear();
    
    // Append the line to the stringstream
    input << line;
  }else{
    throw std::runtime_error("Error reading input line");
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
  std::stringstream ss;
  std::vector<std::string> words;
  
  std::cout<<"Please enter the name of the file without .txt extension : ";
  std::cin>>iName;
  std::cout<<"\n\n";
  
  iName+=".txt";
  ifo.open(iName,std::ios_base::in);
  try{
    while(!ifo.eof()){
    readInOneLine(ifo,ss);
    for(std::string s;ss>>s;)
      words.push_back(s);
    }
  }catch(const std::exception & e){
    std::cerr<<e.what()<<"\n";
  }
  ifo.close();

  showContainer<std::string>(words,"words");
  
  return 0;
}
